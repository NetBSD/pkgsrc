# $NetBSD: icon_themes.mk,v 1.1 2017/08/10 05:41:07 jlam Exp $
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

# Generate the data file for the icon_themes package task.

# ICON_THEMES
#	Package-settable variable for whether to automatically update
#	the GTK+ icon theme directory caches.
#
#	Possible: yes, no
#	Default: yes
#
_PKG_VARS.pkgtasks+=	ICON_THEMES
ICON_THEMES?=		no

FILES_SUBST+=	GTK_UPDATE_ICON_CACHE=${LOCALBASE:Q}/bin/gtk-update-icon-cache
FILES_SUBST+=	GTK2_UPDATE_ICON_CACHE=${LOCALBASE:Q}/bin/gtk2-update-icon-cache
FILES_SUBST+=	GTK3_UPDATE_ICON_CACHE=${LOCALBASE:Q}/bin/gtk-update-icon-cache

# Trigger pkgtasks dependency if needed.
.if "${ICON_THEMES:tl}" == "yes"
USE_PKGTASKS=		yes
.endif

_PKGTASKS_DATA.icon_themes=	${_PKGTASKS_DIR}/icon_themes
_PKGTASKS_DATAFILES+=		${_PKGTASKS_DATA.icon_themes}

# ${ICON_THEMES_cmd} is defined by the plist module.
${_PKGTASKS_DATA.icon_themes}:
	${RUN}${MKDIR} ${.TARGET:H:Q}
	${RUN}exec > ${.TARGET:Q}.tmp
	${RUN}${TEST} "${ICON_THEMES:tl}" = "yes" || exit 0;		\
	cmd=${ICON_THEMES_cmd:Q}"";					\
	${TEST} -n "$$cmd" || cmd=${TRUE:Q}"";				\
	eval $$cmd | while IFS= read themedir; do			\
		${ECHO} "# ICON_THEME: $$themedir";			\
	done >> ${.TARGET:Q}.tmp
	${RUN}${MV} ${.TARGET:Q}.tmp ${.TARGET:Q}
