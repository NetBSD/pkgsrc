#! @SH@
#
# $NetBSD: java-wrapper.sh,v 1.1.1.1 2004/06/04 16:35:07 jmmv Exp $
#
# java-wrapper - Runs different Java implementations transparently.
# Copyright (c) 2004 Julio M. Merino Vidal <jmmv@NetBSD.org>
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

PREFIX="@PREFIX@"
PKG_SYSCONFDIR="@PKG_SYSCONFDIR@"
TR="@TR@"

progname=${0##*/}

err() {
	echo "${progname}: $*" 1>&2
	echo "${progname}: See java-wrapper(1) for more information." 1>&2
	exit 1
}

if [ -f ${HOME}/.java-wrapper.conf ]; then
	. ${HOME}/.java-wrapper.conf
elif [ -f ${PKG_SYSCONFDIR}/java-wrapper.conf ]; then
	. ${PKG_SYSCONFDIR}/java-wrapper.conf
else
	err "cannot open configuration file."
fi

varname=$(echo ${progname} | ${TR} a-z A-Z)
eval impl=\"\$${varname}\"

if [ -z "${impl}" -a -z "${DEFAULT}" ]; then
	err "no mapping defined (${varname} and DEFAULT are empty)."
fi

bin=${PREFIX}/bin/${impl:-${DEFAULT}}-${progname}

if [ ! -f ${bin} ]; then
	err "cannot locate ${bin} (incorrect mapping or missing package)."
fi

${bin} "$@"
