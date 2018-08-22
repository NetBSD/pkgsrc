# $NetBSD: make.mk,v 1.15 2018/08/22 20:48:37 maya Exp $
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
# This Makefile fragment creates a tool called "make" under ${TOOLS_DIR}
# that corresponds to the make program used to build the package.
# This lets a bare "make" invoke the correct program if called from
# within a makefile or script.  It also sets MAKE_PROGRAM to the path
# of that make program.  Lastly, pass ${MAKE_PROGRAM} to GNU configure
# scripts in the MAKE variable so that the scripts will embed the
# correct path to the make program used to build the package
# into the generated Makefiles.
#

# Define MAKE_PROGRAM to be the "make" used to build the package.
.if !empty(_USE_TOOLS:Mgmake)
MAKE_PROGRAM=		${GMAKE}
.elif !empty(_USE_TOOLS:Mimake) && defined(IMAKE_MAKE)
MAKE_PROGRAM=		${IMAKE_MAKE}
.else
MAKE_PROGRAM?=		${MAKE}
.endif

TOOLS_CREATE+=		make
TOOLS_PATH.make=	${MAKE_PROGRAM}

CONFIGURE_ENV+=		MAKE=make
