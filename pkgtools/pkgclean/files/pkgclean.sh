#! @SH@
# $NetBSD: pkgclean.sh,v 1.3 2008/04/29 05:46:08 martin Exp $
#

# Copyright (c) 2005 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Roland Illig <rillig@NetBSD.org>.
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
# Command line parsing
#

pkgsrcdir=${PKGSRCDIR-@PKGSRCDIR@}

case $# in
0)	wrkdir_basename="work";;
1)	wrkdir_basename="$1";;
esac

#
# Sanity checks
#

case $pkgsrcdir in
/*)	;;
*)	echo "$0: error: PKGSRCDIR must be an absolute path." 1>&2
	exit 1;;
esac
case $wrkdir_basename in
*/*)	echo "$0: error: wrkdir_basename must not contain slashes." 1>&2
	exit 1;;
esac

#
# Clean up the pkgsrc directory
#

for wrkdir in "${pkgsrcdir}"/*/*/"${wrkdir_basename}"; do
	case $wrkdir in
	"${pkgsrcdir}/*/*/${wrkdir_basename}") continue;;
	esac

	echo "===> Cleaning in ${wrkdir}"

	# When WRKOBJDIR is set, ${wrkdir_basename} is just a symlink to
	# a real directory, so both must be removed properly.
	if real_wrkdir=`cd "${wrkdir}"/. 2>/dev/null && exec pwd`; then
		rm -rf "${real_wrkdir}"
	fi

	rm -rf "${wrkdir}"
done
