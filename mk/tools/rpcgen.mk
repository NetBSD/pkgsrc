# $NetBSD: rpcgen.mk,v 1.8 2005/06/11 05:22:03 jlam Exp $
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
# Create an rpcgen script that correctly sets the CPP environment
# variable to a stat(2)able path to a C preprocessor, then invokes
# the real rpcgen.
#
TOOLS_CREATE+=		rpcgen
.if !defined(TOOLS_REAL_CMD.rpcgen)
TOOLS_EXECDIRS.rpcgen?=	/bin /sbin /usr/bin /usr/sbin
.  for _d_ in ${TOOLS_EXECDIRS.rpcgen}
.    if exists(${_d_}/rpcgen)
TOOLS_REAL_CMD.rpcgen?=	${_d_}/rpcgen
.    endif
.  endfor
TOOLS_REAL_CMD.rpcgen?=	${FALSE}
.endif
TOOLS_CMD.rpcgen=	${TOOLS_DIR}/bin/rpcgen
.if ${OPSYS} == "NetBSD"
TOOLS_REAL_ARGS.rpcgen?=	-b
.endif
TOOLS_REAL_CMDLINE.rpcgen=	\
	CPP=${WRAPPER_BINDIR:Q}/cpp ${TOOLS_REAL_CMD.rpcgen} ${TOOLS_REAL_ARGS.rpcgen} "$$@"

# Make ${RPCGEN} call the "rpcgen" through the PATH, which should find
# the rpcgen tool wrapper.
#
RPCGEN?=	rpcgen
