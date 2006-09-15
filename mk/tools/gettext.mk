# $NetBSD: gettext.mk,v 1.6 2006/09/15 14:18:41 obache Exp $
#
# Copyright (c) 2006 The NetBSD Foundation, Inc.
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

# These tools are all supplied by the devel/gettext-tools package if there
# is no native tool available.  Don't add "msgfmt" to this list as it's
# treated specially below.
#
_TOOLS.gettext-tools=		gettext msgmerge xgettext
_TOOLS_DEP.gettext-tools=	{gettext-tools>=0.14.5,gettext>=0.10.36}

.for _t_ in ${_TOOLS.gettext-tools}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(USE_TOOLS:C/:.*//:M${_t_})
USE_TOOLS+=	msgfmt
.  endif
.endfor

###
### Handle "msgfmt".  We use either the pkgsrc version or the built-in
### version of msgfmt depending on availability and version.
###
.if !defined(TOOLS_IGNORE.msgfmt) && !empty(USE_TOOLS:C/:.*//:Mmsgfmt)
.  if !empty(PKGPATH:Mdevel/gettext-tools)
MAKEFLAGS+=		TOOLS_IGNORE.msgfmt=
.  else
.    if defined(TOOLS_PLATFORM.msgfmt) && !empty(TOOLS_PLATFORM.msgfmt)
_TOOLS_USE_PKGSRC.msgfmt?=	no
#
# Determine if the platform-supplied msgfmt is new enough to support
# the msgid_plural statement.  We need at least 0.10.36 for GNU msgfmt.
#
# XXX Solaris msgfmt also understands msgid_plural but more tests are
# XXX needed to take advantage of this.
# XXX
.      if !defined(_TOOLS_USE_MSGFMT_SH)
_TOOLS_VERSION.msgfmt!=		${TOOLS_PLATFORM.msgfmt} --version |	\
				${AWK} '{ print $$4; exit }'
_TOOLS_USE_MSGFMT_SH!=							\
	if ${PKG_ADMIN} pmatch "gettext>0.10.35"			\
			gettext-${_TOOLS_VERSION.msgfmt:Q}; then	\
		${ECHO} no;						\
	else								\
		${ECHO} yes;						\
	fi
.      endif
MAKEVARS+=	_TOOLS_USE_MSGFMT_SH
.    else
_TOOLS_USE_PKGSRC.msgfmt=	yes
.    endif

# If we're not using the builtin gettext implementation, then we should
# definitely be using the pkgsrc version of msgfmt (gettext-tools).
#
CHECK_BUILTIN.gettext:=	yes
.    include "../../devel/gettext-lib/builtin.mk"
CHECK_BUILTIN.gettext:=	no
.    if !empty(USE_BUILTIN.gettext:M[nN][oO])
_TOOLS_USE_PKGSRC.msgfmt=	yes
.    endif

.    if !empty(_TOOLS_USE_PKGSRC.msgfmt:M[yY][eE][sS])
TOOLS_CREATE+=		msgfmt
TOOLS_DEPENDS.msgfmt?=	${_TOOLS_DEP.gettext-tools}:../../devel/gettext-tools
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.msgfmt=${TOOLS_DEPENDS.msgfmt:C/:.*//}
TOOLS_PATH.msgfmt=	${TOOLS_PREFIX.msgfmt}/bin/msgfmt
.    elif defined(_TOOLS_USE_MSGFMT_SH) && \
          !empty(_TOOLS_USE_MSGFMT_SH:M[yY][eE][sS])
USE_TOOLS+=		awk sh
TOOLS_PATH.msgfmt=	${PKGSRCDIR}/mk/tools/msgfmt.sh
TOOLS_SCRIPT.msgfmt=	AWK=${TOOLS_AWK:Q} CAT=${TOOLS_CAT:Q}		\
			MSGFMT=${TOOLS_PLATFORM.msgfmt:Q}		\
			${TOOLS_SH} ${TOOLS_PATH.msgfmt} "$$@"
.    endif
.  endif
.endif

.for _t_ in ${_TOOLS.gettext-tools}
.  if !defined(TOOLS_IGNORE.${_t_}) && !empty(USE_TOOLS:C/:.*//:M${_t_})
.    if !empty(_TOOLS_USE_PKGSRC.msgfmt:M[yY][eE][sS])
_TOOLS_USE_PKGSRC.${_t_}=	yes
.    elif defined(TOOLS_PLATFORM.msgfmt) && !empty(TOOLS_PLATFORM.msgfmt)
_TOOLS_USE_PKGSRC.${_t_}?=	no
.    else
_TOOLS_USE_PKGSRC.${_t_}?=	yes
.    endif
.    if !empty(PKGPATH:Mdevel/gettext-tools)
MAKEFLAGS+=		TOOLS_IGNORE.${_t_}=
.    elif !empty(_TOOLS_USE_PKGSRC.${_t_}:M[yY][eE][sS])
TOOLS_DEPENDS.${_t_}?=	${_TOOLS_DEP.gettext-tools}:../../devel/gettext-tools
TOOLS_CREATE+=		${_t_}
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.${_t_}=${TOOLS_DEPENDS.${_t_}:C/:.*//}
TOOLS_PATH.${_t_}=	${TOOLS_PREFIX.${_t_}}/bin/${_t_}
.    endif
.  endif
.endfor
