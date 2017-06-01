# $NetBSD: fonts.mk,v 1.1 2017/06/01 02:06:04 jlam Exp $
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

# Generate the data file for the fonts package task.

# PKG_UPDATE_FONTS_DB
#	Whether to automatically update the fonts databases.
#
#	Possible: yes, no
#	Default: yes
#
_USER_VARS.pkgtasks+=	PKG_UPDATE_FONTS_DB
PKG_UPDATE_FONTS_DB?=	yes
FILES_SUBST+=		PKG_UPDATE_FONTS_DB=${PKG_UPDATE_FONTS_DB:Q}

# FONTS_DIRS.<type>
#	List of directories in which the font databases are updated.
#	The supported font types are:
#
#	ttf	TrueType fonts
#	type1	Type1 fonts
#	x11	X fonts, e.g., PCF, SNF, BDF, etc.
#
_PKG_VARS.pkgtasks+=	FONTS_DIRS.ttf FONTS.DIRS.type1 FONTS_DIRS.x11
FONTS_DIRS.ttf?=	# empty
FONTS_DIRS.type1?=	# empty
FONTS_DIRS.x11?=	# empty

# Trigger pkgtasks dependency if needed.
_PKGTASKS_DATAVARS.fonts=	FONTS_DIRS.ttf FONTS.DIRS.type1 FONTS_DIRS.x11
.for _var_ in ${_PKGTASKS_DATAVARS.fonts}
.  if !empty(${_var_})
USE_PKGTASKS=		yes
.  endif
.endfor

_FONTS_DIRS.x11=	# empty
.if !empty(FONTS_DIRS.ttf:M*)
.  if ${X11_TYPE} == "modular"
USE_TOOLS+=		mkfontscale:run
FILES_SUBST+=		MKFONTSCALE=${TOOLS_PATH.mkfontscale:Q}
.  else
USE_TOOLS+=		ttmkfdir:run
FILES_SUBST+=		TTMKFDIR=${TOOLS_PATH.ttmkfdir:Q}
.  endif
_FONTS_DIRS.x11+=	${FONTS_DIRS.ttf}
.endif
.if !empty(FONTS_DIRS.type1:M*)
.  if ${X11_TYPE} == "modular"
USE_TOOLS+=		mkfontscale:run
FILES_SUBST+=		MKFONTSCALE=${TOOLS_PATH.mkfontscale:Q}
.  else
USE_TOOLS+=		type1inst:run
FILES_SUBST+=		TTMKFDIR=${TOOLS_PATH.type1inst:Q}
.  endif
_FONTS_DIRS.x11+=	${FONTS_DIRS.type1}
.endif
_FONTS_DIRS.x11+=	${FONTS_DIRS.x11}
.if !empty(_FONTS_DIRS.x11:M*)
USE_TOOLS+=		mkfontdir:run
FILES_SUBST+=		MKFONTDIR=${TOOLS_PATH:mkfontdir:Q}
.  if ${X11_TYPE} == "modular"
DEPENDS+=		encodings-[0-9]*:../../fonts/encodings
X11_ENCODINGSDIR?=	${X11BASE}/share/fonts/X11/encodings
.  else
X11_ENCODINGSDIR?=	${X11BASE}/lib/fonts/X11/encodings
.  endif
FILES_SUBST+=		X11_ENCODINGSDIR=${X11_ENCODINGSDIR:Q}
.endif

_PKGTASKS_DATA.fonts=	${_PKGTASKS_DIR}/fonts
_PKGTASKS_DATAFILES+=	${_PKGTASKS_DATA.fonts}

${_PKGTASKS_DATA.fonts}:
	${RUN}${MKDIR} ${.TARGET:H:Q}
	${RUN}exec > ${.TARGET}.tmp
.for _fonttype_ in ttf type1 x11
.  for _fontdir_ in ${FONTS_DIRS.${_fonttype_}:S|^${PREFIX}/||g}
	${RUN}${ECHO} "# FONTS: "${_fontdir_:Q} ${_fonttype_:Q} >> ${.TARGET}.tmp
.  endfor
.endfor
	${RUN}${MV} ${.TARGET:Q}.tmp ${.TARGET:Q}
