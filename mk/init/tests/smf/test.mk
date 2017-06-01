# $NetBSD: test.mk,v 1.1 2017/06/01 02:08:05 jlam Exp $
#
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

INIT_SYSTEM=	smf

.include "${PKGSRCDIR}/mk/init/bsd.init-vars.mk"

# Definitions used by smf.mk that are not assigned default values.
CAT?=			cat
CHMOD?=			chmod
CP?=			cp
ECHO?=			echo
INSTALL_DATA?=		${CP}
INSTALL_SCRIPT?=	${CP}
LOCALBASE?=		/usr/pkg
MKDIR?=			mkdir -p
PKGMANDIR?=		share/man
PREFIX?=		${LOCALBASE}
RUN?=			# empty; show all commands executed
SED?=			sed
SH?=			/bin/sh
STEP_MSG?=		${ECHO} "!!!"
VARBASE?=		/var

# Turn ${FILES_SUBST} into a sed(1) script.
FILES_SUBST+=		PREFIX=${PREFIX:Q}
FILES_SUBST+=		VARBASE=${VARBASE:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

# Override any other default definitions so that generated files go into
# a work directory.
#
DESTDIR=	${.CURDIR}/destdir
FILESDIR=	${.CURDIR}
WRKDIR=		${.CURDIR}/work

# Target to write the value of a variable to standard output.
.PHONY: show-var
show-var:
	@${ECHO} ${${VARNAME}:Q}
