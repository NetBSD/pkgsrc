# $NetBSD: texinfo.mk,v 1.8 2005/07/17 21:36:24 jlam Exp $
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
# Create an install-info script that is a "no operation" command, as
# registration of info files is handled by the INSTALL script.
#
TOOLS_NOOP+=		install-info
CONFIGURE_ENV+=		INSTALL_INFO=${TOOLS_CMD.install-info:Q}
MAKE_ENV+=		INSTALL_INFO=${TOOLS_CMD.install-info:Q}

# Create a makeinfo script that will invoke the right makeinfo command
# if USE_MAKEINFO is "yes" or will exit on error if not.  MAKEINFO is
# defined by mk/texinfo.mk if USE_MAKEINFO is "yes".
#
USE_MAKEINFO?=		no
.if empty(USE_MAKEINFO:M[nN][oO])
TOOLS_CREATE+=		makeinfo
TOOLS_PATH.makeinfo=	${MAKEINFO:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
TOOLS_ARGS.makeinfo=	${MAKEINFO:C/^/_asdf_/1:N_asdf_*}
.else
TOOLS_BROKEN+=		makeinfo
.endif
CONFIGURE_ENV+=		MAKEINFO=${TOOLS_CMD.makeinfo:Q}
MAKE_ENV+=		MAKEINFO=${TOOLS_CMD.makeinfo:Q}
