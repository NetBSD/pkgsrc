# $NetBSD: bootstrap.mk,v 1.7 2005/10/09 20:19:26 heinz Exp $
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
# bootstrap.mk contains settings matching the contents of
# pkgsrc/bootstrap/bootstrap.  Where we install the bootstrap versions
# of tools, we point TOOLS_PLATFORM.* to them so that pkgsrc knows
# that they are system-supplied and won't need replacement by pkgsrc
# versions of those tools.
#
# XXX This file should go away and the bootstrap script should be
# XXX taught to write out the correct TOOLS_PLATFORM.* definitions
# XXX on its own, based on the configuration used.
# 

.if ${OPSYS} == "AIX"
TOOLS_PLATFORM.install?=	${LOCALBASE}/bin/install-sh
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.strip?=		${LOCALBASE}/bin/strip
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "Darwin"
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "DragonFly"
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "FreeBSD"
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "HPUX"
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "Interix"
TOOLS_PLATFORM.install?=	${LOCALBASE}/bin/install-sh
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "IRIX"
TOOLS_PLATFORM.install?=	${LOCALBASE}/bin/install-sh
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "Linux"
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "NetBSD"
# NetBSD has everything.

.elif ${OPSYS} == "OpenBSD"
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "OSF1"
TOOLS_PLATFORM.install?=	${LOCALBASE}/bin/install-sh
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "SunOS"
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "UnixWare"
TOOLS_PLATFORM.mkdir?=		${LOCALBASE}/sbin/mkdir-sh -p
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.else
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar
.endif
