# Copyright (c) 2017 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Johnny C. Lam.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

task_load createfile
task_load icon_themes
task_load unittest

test_setup()
{
	: ${CAT:=cat}
	: ${MKDIR:=mkdir}

	PKG_PREFIX="${TEST_CURDIR}"
	PKG_DESTDIR=

	datafile="datafile"
	${CAT} > $datafile << EOF
# ICON_THEME: hicolor
# ICON_THEME: ${PKG_PREFIX}/share/icons/gnome
EOF

	${MKDIR} -p share/icons/hicolor
	${MKDIR} -p share/icons/gnome

	task_createfile share/icons/hicolor/index.theme
	task_createfile share/icons/gnome/index.theme

	GTK3_UPDATE_ICON_CACHE="mock_gtk_update_icon_cache"
	GTK2_UPDATE_ICON_CACHE="mock_gtk_update_icon_cache"
	GTK_UPDATE_ICON_CACHE="mock_gtk_update_icon_cache"
}

test_destdir_setup()
{
	: ${MKDIR:=mkdir}
	: ${MV:=mv}

	PKG_DESTDIR="${TEST_CURDIR}/destdir"
	${MKDIR} -p "${PKG_DESTDIR}${PKG_PREFIX}"
	${MV} share "${PKG_DESTDIR}${PKG_PREFIX}"
}

# Mock icon cache update command.
mock_gtk_update_icon_cache()
{
	while [ $# -gt 0 ]; do
		case $1 in
		-*)	shift ;;
		*)	break ;;
		esac
	done
	[ $# -gt 0 ] || return 127
	local themedir="$1"; shift
	local theme="$themedir/index.theme"
	local cache="$themedir/icon-theme.cache"

	[ -f "$theme" ] || return 1
	task_createfile "$cache"
}

test1()
{
	describe="add"
	if task_icon_themes add < $datafile; then
		: "success"
	else
		return 1
	fi
	# Assert the caches are all present.
	for themedir in hicolor gnome; do
		cache="${PKG_PREFIX}/share/icons/$themedir/icon-theme.cache"
		if [ ! -f "$cache" ]; then
			describe="$describe: $cache missing!"
			return 1
		fi
	done
	return 0
}

test2()
{
	: ${RM:=rm}

	describe="add with missing index.theme"
	local theme="${PKG_PREFIX}/share/icons/hicolor/index.theme"
	${RM} "$theme"
	if task_icon_themes add < $datafile; then
		# expected to fail
		return 1
	fi
	return 0
}

test3()
{
	describe="remove"
	task_icon_themes add < $datafile
	if task_icon_themes remove < $datafile; then
		: "success"
	else
		return 1
	fi
	# Assert the caches are gone.
	for themedir in hicolor gnome; do
		cache="${PKG_PREFIX}/share/icons/$themedir/icon-theme.cache"
		if [ -f "$cache" ]; then
			describe="$describe: $cache present!"
			return 1
		fi
	done
	return 0
}

test4()
{
	describe="remove with no caches"
	if task_icon_themes remove < $datafile; then
		: "success"
	else
		return 1
	fi
	# Assert the caches are gone.
	for themedir in hicolor gnome; do
		cache="${PKG_PREFIX}/share/icons/$themedir/icon-theme.cache"
		if [ -f "$cache" ]; then
			describe="$describe: $cache present!"
			return 1
		fi
	done
	return 0
}

test5()
{
	describe="remove during postremove"
	if task_icon_themes remove postremove < $datafile; then
		: "success"
	else
		return 1
	fi
	# Assert the caches have been recreated.
	for themedir in hicolor gnome; do
		cache="${PKG_PREFIX}/share/icons/$themedir/icon-theme.cache"
		if [ ! -f "$cache" ]; then
			describe="$describe: $cache missing!"
			return 1
		fi
	done
	return 0
}

test6()
{
	describe="add with PKG_DESTDIR"
	test_destdir_setup
	if task_icon_themes add < $datafile; then
		: "success"
	else
		return 1
	fi
	# Assert the caches are all present.
	for themedir in hicolor gnome; do
		cache="${PKG_PREFIX}/share/icons/$themedir/icon-theme.cache"
		cache="${PKG_DESTDIR}$cache"
		if [ ! -f "$cache" ]; then
			describe="$describe: $cache missing!"
			return 1
		fi
	done
	return 0
}

test7()
{
	: ${RM:=rm}

	describe="add with missing index.theme with PKG_DESTDIR"
	test_destdir_setup
	local theme="${PKG_PREFIX}/share/icons/hicolor/index.theme"
	theme="${PKG_DESTDIR}$theme"
	${RM} "$theme"
	if task_icon_themes add < $datafile; then
		# expected to fail
		return 1
	fi
	return 0
}

test8()
{
	describe="remove with PKG_DESTDIR"
	test_destdir_setup
	task_icon_themes add < $datafile
	if task_icon_themes remove < $datafile; then
		: "success"
	else
		return 1
	fi
	# Assert the caches are gone.
	for themedir in hicolor gnome; do
		cache="${PKG_PREFIX}/share/icons/$themedir/icon-theme.cache"
		cache="${PKG_DESTDIR}$cache"
		if [ -f "$cache" ]; then
			describe="$describe: $cache present!"
			return 1
		fi
	done
	return 0
}

test9()
{
	describe="remove with no caches with PKG_DESTDIR"
	test_destdir_setup
	if task_icon_themes remove < $datafile; then
		: "success"
	else
		return 1
	fi
	# Assert the caches are gone.
	for themedir in hicolor gnome; do
		cache="${PKG_PREFIX}/share/icons/$themedir/icon-theme.cache"
		cache="${PKG_DESTDIR}$cache"
		if [ -f "$cache" ]; then
			describe="$describe: $cache present!"
			return 1
		fi
	done
	return 0
}

test10()
{
	describe="remove during postremove with PKG_DESTDIR"
	if task_icon_themes remove postremove < $datafile; then
		: "success"
	else
		return 1
	fi
	# Assert the caches have been recreated.
	for themedir in hicolor gnome; do
		cache="${PKG_PREFIX}/share/icons/$themedir/icon-theme.cache"
		cache="${PKG_DESTDIR}$cache"
		if [ ! -f "$cache" ]; then
			describe="$describe: $cache missing!"
			return 1
		fi
	done
	return 0
}

task_run_tests "$@"
