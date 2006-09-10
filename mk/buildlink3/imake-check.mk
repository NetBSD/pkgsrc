# $NetBSD: imake-check.mk,v 1.5 2006/09/10 16:39:31 tron Exp $
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
# This is a "subroutine" that can be included to detect whether the
# X11 distribution we are using with pkgsrc has certain X11 components
# built-in to the distribution.
#
# The following variables must be defined before including this file:
#
#    BUILTIN_IMAKE_CHECK is a list of <pkg>:<symbol> pairs, where <pkg>
#	is the package to check for, and <symbol> is the imake symbol
#	to check in the imake config files.
#
# After including this file, the following variables are defined:
#
#    BUILTIN_IMAKE_CHECK.<pkg> is "yes" or "no" depending on whether the
#	specified imake symbol is "true" in the imake config files.
#
# An example use is:
#
# BUILTIN_IMAKE_CHECK:=	Xft2:BuildXftLibrary
# .include "../../mk/buildlink3/imake-check.mk"
#

.for _pair_ in ${BUILTIN_IMAKE_CHECK}
USE_TOOLS+=	cat:pkgsrc echo:pkgsrc grep:pkgsrc mkdir:pkgsrc		\
		rm:pkgsrc test:pkgsrc
USE_TOOLS+=	imake:pkgsrc ${IMAKE_TOOLS:S/$/:pkgsrc/}	# XXX
IMAKE?=		${X11BASE}/bin/imake				# XXX

.  if !defined(BUILTIN_IMAKE_CHECK.${_pair_:C/\:[^:]*$//})
BUILTIN_IMAKE_CHECK.${_pair_:C/\:[^:]*$//}!=				\
	if ${SETENV} CAT=${CAT:Q} ECHO=${ECHO:Q} GREP=${GREP:Q}		\
		IMAKE=${IMAKE:Q} IMAKE_MAKE=${IMAKE_MAKE:Q}		\
		MKDIR=${MKDIR:Q} PATH_ORIG=${_PATH_ORIG:Q}		\
		RM=${RM:Q} TEST=${TEST:Q}				\
		X11BASE=${X11BASE:Q}					\
	   ${SH} ${.CURDIR}/../../mk/buildlink3/imake-check		\
		${_pair_:C/^[^:]*\://};					\
	then								\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.  endif
MAKEVARS+=	BUILTIN_IMAKE_CHECK.${_pair_:C/\:[^:]*$//}
.endfor
