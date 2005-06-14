# $NetBSD: imake.mk,v 1.14 2005/06/14 07:12:23 jlam Exp $
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
# This Makefile fragment defines additional variables that are used
# by packages that need imake and xmkmf.
#
# Variables defined by this file are:
#
#	XMKMF, TOOLS_XMKMF
#		command to create all Makefiles from Imakefiles,
#		usually "xmkmf -a".
#
# Optional variables that may be defined by the package are:
#
#	IMAKEOPTS	Options to pass to imake
#	XMKMF_FLAGS	Options to pass to xmkmf
#
# A platform/${OPSYS}.mk file may note that additional tools are
# required when using imake by setting IMAKE_TOOLS to the appropriate
# value, e.g. IMAKE_TOOLS+=gmake to use GNU make to build packages
# that use imake.
#
# This file needs to be included before replace.mk as it modifies the
# PKGSRC_USE_TOOLS and USE_TOOLS variables that are used by replace.mk.
#

.if defined(USE_IMAKE)
USE_TOOLS+=	imake xmkmf
.endif

# imake and xmkmf imply each other
.if !empty(PKGSRC_USE_TOOLS:Mimake) || !empty(PKGSRC_USE_TOOLS:Mxmkmf)
PKGSRC_USE_TOOLS+=	imake xmkmf
.endif
.if !empty(USE_TOOLS:Mimake) || !empty(USE_TOOLS:Mxmkmf)
USE_TOOLS+=		imake xmkmf
.endif

# Add any extra tools that may be required when using imake, e.g. gmake.
.if !empty(USE_TOOLS:Mimake)
USE_TOOLS+=		${IMAKE_TOOLS:Nimake}
.endif

TOOLS_REAL_ARGS.imake?=	${IMAKEOPTS}
TOOLS_REAL_ARGS.xmkmf?=	${XMKMF_FLAGS}

TOOLS_XMKMF=		${${_TOOLS_VARNAME.xmkmf}} -a
XMKMF=			${${_TOOLS_VARNAME.xmkmf}} -a
