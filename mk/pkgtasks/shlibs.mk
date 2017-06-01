# $NetBSD: shlibs.mk,v 1.1 2017/06/01 02:06:04 jlam Exp $
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

# Generate the data file for the shlibs package task.

# RUN_LDCONFIG
#	Whether to automatically update the library search paths cache.
#
#	Possible: yes, no
#	Default: "yes" for a.out platforms, "no" otherwise
#
_USER_VARS.pkgtasks+=	RUN_LDCONFIG
RUN_LDCONFIG?=		${"${SHLIB_TYPE}" == "a.out":?yes:no}

# Trigger pkgtasks dependency if needed.
.if "${RUN_LDCONFIG:tl}" == "yes"
USE_PKGTASKS=		yes
.endif

_PKGTASKS_DATA.shlibs=	${_PKGTASKS_DIR}/shlibs
_PKGTASKS_DATAFILES+=	${_PKGTASKS_DATA.shlibs}

# Directories to add to the library search path cache.
PKG_SHLIB_DIRS=		lib

# Strip leading "${PREFIX}/" from the directory pathnames.
_PKG_SHLIB_DIRS=	${PKG_SHLIB_DIRS:S|^${PREFIX}/||g}

${_PKGTASKS_DATA.shlibs}:
	${RUN}${MKDIR} ${.TARGET:H:Q}
	${RUN}exec > ${.TARGET}.tmp
	${RUN}${TEST} "${RUN_LDCONFIG:tl}" != "yes" || \
	${ECHO} "# SHLIB: "${_PKG_SHLIB_DIRS:Q} >> ${.TARGET}.tmp
	${RUN}${MV} ${.TARGET:Q}.tmp ${.TARGET:Q}
