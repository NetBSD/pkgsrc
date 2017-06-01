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
task_load fonts
task_load unittest

test_setup()
{
	PKG_PREFIX="${TEST_CURDIR}"
	PKG_DESTDIR=

	fontdir_ttf="share/fonts/ttf"
	fontdir_type1="share/fonts/type1"
	fontdir_x11="share/fonts/x11"

	# Prevent current directory from being auto-removed because it's empty.
	task_createfile non-empty

	MKFONTDIR="mock_mkfontdir"
	MKFONTSCALE="mock_mkfontscale"
	TTMKFDIR="mock_ttmkfdir"
	TYPE1INST="mock_type1inst"
}

test_destdir_setup()
{
	: ${MKDIR:=mkdir}
	: ${MV:=mv}

	PKG_DESTDIR="${TEST_CURDIR}/destdir"
	${MKDIR} -p "${PKG_DESTDIR}${PKG_DESTDIR}"
	${MV} non-empty "${PKG_DESTDIR}${PKG_DESTDIR}"
}

# Mock font index generator utilities.
mock_mkfontdir()
{
	task_createfile encodings.dir
}

mock_mkfontscale()
{
	task_createfile fonts.scale
}

mock_ttmkfdir()
{
	task_createfile fonts.dir
	task_createfile fonts.scale
}

mock_type1inst()
{
	task_createfile type1inst.log
	task_createfile Fontmap.1
	task_createfile Fontmap.2
	task_createfile Fontmap.3
}

test1()
{
	: ${MKDIR:=mkdir}

	describe="empty ttf fonts dir"
	${MKDIR} -p "$fontdir_ttf"
	echo "# FONTS: $fontdir_ttf ttf" | task_fonts add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$fontdir_ttf" ]; then
		describe="$describe: ${PKG_PREFIX}/$fontdir_ttf exists!"
		return 1
	fi
	return 0
}

test2()
{
	: ${MKDIR:=mkdir}

	describe="non-empty ttf fonts dir"
	${MKDIR} -p "$fontdir_ttf"
	task_createfile "${PKG_PREFIX}/$fontdir_ttf/font1"
	echo "# FONTS: $fontdir_ttf ttf" | task_fonts add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -d "${PKG_PREFIX}/$fontdir_ttf" ]; then
		describe="$describe: ${PKG_PREFIX}/$fontdir_ttf missing!"
		return 1
	fi
	if [ ! -f "${PKG_PREFIX}/$fontdir_ttf/encodings.dir" ]; then
		describe="$describe: x11 encodings missing!"
		return 1
	fi
	return 0
}

test3()
{
	: ${MKDIR:=mkdir}

	describe="empty type1 fonts dir"
	${MKDIR} -p "$fontdir_type1"
	echo "# FONTS: $fontdir_type1 type1" | task_fonts add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$fontdir_type1" ]; then
		describe="$describe: ${PKG_PREFIX}/$fontdir_type1 exists!"
		return 1
	fi
	return 0
}

test4()
{
	: ${MKDIR:=mkdir}

	describe="non-empty type1 fonts dir"
	${MKDIR} -p "$fontdir_type1"
	task_createfile "${PKG_PREFIX}/$fontdir_type1/font1"
	echo "# FONTS: $fontdir_type1 type1" | task_fonts add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -d "${PKG_PREFIX}/$fontdir_type1" ]; then
		describe="$describe: ${PKG_PREFIX}/$fontdir_type1 missing!"
		return 1
	fi
	if [ ! -f "${PKG_PREFIX}/$fontdir_type1/encodings.dir" ]; then
		describe="$describe: x11 encodings missing!"
		return 1
	fi
	return 0
}

test5()
{
	: ${MKDIR:=mkdir}

	describe="empty x11 fonts dir"
	${MKDIR} -p "$fontdir_x11"
	echo "# FONTS: $fontdir_x11 x11" | task_fonts add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$fontdir_x11" ]; then
		describe="$describe: ${PKG_PREFIX}/$fontdir_x11 exists!"
		return 1
	fi
	return 0
}

test6()
{
	: ${MKDIR:=mkdir}

	describe="non-empty x11 fonts dir"
	${MKDIR} -p "$fontdir_x11"
	task_createfile "${PKG_PREFIX}/$fontdir_x11/font1"
	echo "# FONTS: $fontdir_x11 x11" | task_fonts add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -d "${PKG_PREFIX}/$fontdir_x11" ]; then
		describe="$describe: ${PKG_PREFIX}/$fontdir_x11 missing!"
		return 1
	fi
	return 0
}

test7()
{
	: ${MKDIR:=mkdir}

	describe="empty ttf fonts dir with PKG_DESTDIR"
	test_destdir_setup
	local fontdir="${PKG_DESTDIR}${PKG_PREFIX}/$fontdir_ttf"
	${MKDIR} -p "$fontdir"
	echo "# FONTS: $fontdir_ttf ttf" | task_fonts add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ -d "$fontdir" ]; then
		describe="$describe: $fontdir exists!"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$fontdir_ttf" ]; then
		describe="$describe: ${PKG_PREFIX}/$fontdir_ttf exists!"
		return 1
	fi
	return 0
}

test8()
{
	: ${MKDIR:=mkdir}

	describe="non-empty ttf fonts dir with PKG_DESTDIR"
	test_destdir_setup
	local fontdir="${PKG_DESTDIR}${PKG_PREFIX}/$fontdir_ttf"
	${MKDIR} -p "$fontdir"
	task_createfile "$fontdir/font1"
	echo "# FONTS: $fontdir_ttf ttf" | task_fonts add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -d "$fontdir" ]; then
		describe="$describe: $fontdir missing!"
		return 1
	fi
	if [ ! -f "$fontdir/encodings.dir" ]; then
		describe="$describe: x11 encodings missing!"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$fontdir_ttf" ]; then
		describe="$describe: ${PKG_PREFIX}/$fontdir_ttf exists!"
		return 1
	fi
	return 0
}

test9()
{
	: ${MKDIR:=mkdir}

	describe="empty type1 fonts dir with PKG_DESTDIR"
	test_destdir_setup
	local fontdir="${PKG_DESTDIR}${PKG_PREFIX}/$fontdir_type1"
	${MKDIR} -p "$fontdir"
	echo "# FONTS: $fontdir_type1 type1" | task_fonts add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ -d "$fontdir" ]; then
		describe="$describe: $fontdir exists!"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$fontdir_type1" ]; then
		describe="$describe: ${PKG_PREFIX}/$fontdir_type1 exists!"
		return 1
	fi
	return 0
}

test10()
{
	: ${MKDIR:=mkdir}

	describe="non-empty type1 fonts dir with PKG_DESTDIR"
	test_destdir_setup
	local fontdir="${PKG_DESTDIR}${PKG_PREFIX}/$fontdir_type1"
	${MKDIR} -p "$fontdir"
	task_createfile "$fontdir/font1"
	echo "# FONTS: $fontdir_type1 type1" | task_fonts add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -d "$fontdir" ]; then
		describe="$describe: $fontdir missing!"
		return 1
	fi
	if [ ! -f "$fontdir/encodings.dir" ]; then
		describe="$describe: x11 encodings missing!"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$fontdir_type1" ]; then
		describe="$describe: ${PKG_PREFIX}/$fontdir_type1 exists!"
		return 1
	fi
	return 0
}

test11()
{
	: ${MKDIR:=mkdir}

	describe="empty x11 fonts dir with PKG_DESTDIR"
	test_destdir_setup
	local fontdir="${PKG_DESTDIR}${PKG_PREFIX}/$fontdir_x11"
	${MKDIR} -p "$fontdir"
	echo "# FONTS: $fontdir_x11 x11" | task_fonts add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ -d "$fontdir" ]; then
		describe="$describe: $fontdir exists!"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$fontdir_x11" ]; then
		describe="$describe: ${PKG_PREFIX}/$fontdir_x11 exists!"
		return 1
	fi
	return 0
}

test12()
{
	: ${MKDIR:=mkdir}

	describe="non-empty x11 fonts dir with PKG_DESTDIR"
	test_destdir_setup
	local fontdir="${PKG_DESTDIR}${PKG_PREFIX}/$fontdir_x11"
	${MKDIR} -p "$fontdir"
	task_createfile "$fontdir/font1"
	echo "# FONTS: $fontdir_x11 x11" | task_fonts add
	if [ $? -gt 0 ]; then
		return 1
	fi
	if [ ! -d "$fontdir" ]; then
		describe="$describe: $fontdir missing!"
		return 1
	fi
	if [ -d "${PKG_PREFIX}/$fontdir_x11" ]; then
		describe="$describe: ${PKG_PREFIX}/$fontdir_x11 exists!"
		return 1
	fi
	return 0
}

task_run_tests "$@"
