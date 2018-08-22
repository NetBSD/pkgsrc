#!/bin/sh
#
# $NetBSD: msgfmt.sh,v 1.35 2018/08/22 20:48:37 maya Exp $
#
# Copyright (c) 2006 The NetBSD Foundation, Inc.
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
#
#
# Copyright (c) 2004, 2005, 2006 Julio M. Merino Vidal <jmmv@NetBSD.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name of author nor the names of its contributors may
#    be used to endorse or promote products derived from this software
#    without specific prior written permission.
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
#

# If you make changes to this file, please test that it can process all
# of the *.po files in each of the following packages:
#
#	databases/libgnomedb
#	devel/libgnome
#	fonts/fontforge
#	multimedia/gmencoder
#	multimedia/gnome2-media
#	net/gtk-gnutella
#	sysutils/gnome-vfs
#	wm/icewm
#	www/epiphany
#	x11/matchbox-panel
#

: ${AWK=awk}
: ${CAT=cat}
: ${MSGFMT=/usr/bin/msgfmt}
: ${TEE=tee}

case "${MSGFMT}" in
/*)	;;
*)	echo 1>&2 "$0: \`\`${MSGFMT}'' must be an absolute pathname."
	exit 1
	;;
esac
if test ! -x "${MSGFMT}"; then
	echo 1>&2 "$0: \`\`${MSGFMT}'' does not exist."
	exit 1
fi

# Parse the command line options.
version=
pofile=
debug=
cmd="${MSGFMT}"
while test $# -gt 0; do
	case "$1" in
	--debug)
		debug=yes; shift
		;;
	--version)
		version="$1"
		cmd="$cmd $1"; shift
		;;
	--statistics|--tcl)
		cmd="$cmd $1"; shift
		;;
	-[aDodl]|--alignment|--directory|--output-file)
		cmd="$cmd $1 $2"; shift; shift;
		;;
	-c)
		# skip all checks
		shift
		;;
	[!-]*|-)
		pofile="$1"
		cmd="$cmd -"; shift
		;;
	*)
		cmd="$cmd $1"; shift
		;;
	esac
done

# If we are asked for just the version, then avoid spawning awk.
test -z "$version" || exec $cmd
test -n "$pofile" || exec $cmd

# If --debug is specified, then dump the output from the awk script
# to $pofile.debug along the way.
#
if test -z "$debug"; then
	debug="${CAT}"
else
	debug="${TEE} $pofile.debug"
fi

# If the input file cannot be found as named, then also search for a file
# with the same name that ends in ".po".
#
if test "$pofile" != "-" -a ! -e "$pofile"; then
	popofile=""
	for extension in po pot; do
		if test -e "$pofile.$extension"; then
			popofile="$pofile.$extension"
			break;
		fi
	done
	if test "x$popofile" = "x"; then
		echo 1>&2 "$0: error while opening \"$pofile\" for reading: No such file or directory"
		exit 1
	fi
	pofile="$popofile"
fi

${CAT} $pofile | \
if test "${MSGFMT_STRIP_MSGCTXT}" = "yes"; then
	${AWK} -f ${PKGSRCDIR}/mk/tools/msgfmt-msgctxt.awk
else
	${CAT}
fi | if test "$MSGFMT_STRIP_MSGID_PLURAL" = "yes"; then
	${AWK} -f ${PKGSRCDIR}/mk/tools/msgfmt-msgid_plural.awk
else
	${CAT}
fi | $debug | $cmd
