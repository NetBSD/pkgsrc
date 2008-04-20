# $NetBSD: pkg-config.mk,v 1.9 2008/04/20 19:32:31 jmmv Exp $
#
# Copyright (c) 2005 The NetBSD Foundation, Inc.
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
# 3. All advertising materials mentioning features or use of this software
#    must display the following acknowledgement:
#        This product includes software developed by the NetBSD
#        Foundation, Inc. and its contributors.
# 4. Neither the name of The NetBSD Foundation nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
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
# Override the location where pkg-config searches for *.pc files in the
# pkg-config wrapper script.
#
_PKG_CONFIG_LIBDIR?=	${BUILDLINK_DIR}/lib/pkgconfig:${BUILDLINK_DIR}/share/pkgconfig
_PKG_CONFIG_LOG?=	${WRKDIR}/.pkg-config.log

TOOLS_SCRIPT.pkg-config=	\
	PKG_CONFIG_LIBDIR=${_PKG_CONFIG_LIBDIR:Q} PKG_CONFIG_PATH= ${TOOLS_SCRIPT_DFLT.pkg-config}

CONFIGURE_ENV+=	PKG_CONFIG=${TOOLS_CMD.pkg-config:Q}
CONFIGURE_ENV+=	PKG_CONFIG_LIBDIR=${_PKG_CONFIG_LIBDIR:Q}
CONFIGURE_ENV+=	PKG_CONFIG_LOG=${_PKG_CONFIG_LOG:Q}
CONFIGURE_ENV+=	PKG_CONFIG_PATH=
MAKE_ENV+=	PKG_CONFIG=${TOOLS_CMD.pkg-config:Q}
MAKE_ENV+=	PKG_CONFIG_LIBDIR=${_PKG_CONFIG_LIBDIR:Q}
MAKE_ENV+=	PKG_CONFIG_LOG=${_PKG_CONFIG_LOG:Q}
MAKE_ENV+=	PKG_CONFIG_PATH=

.if defined(PKG_DEVELOPER)
post-build: pkgconfig-post-build

pkgconfig-post-build:
	@if ${TEST} -f ${_PKG_CONFIG_LOG}; then \
		${ECHO} "*** Please use pkgtools/verifypc to sanity check dependencies."; \
	fi
.endif
