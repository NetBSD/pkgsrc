# $NetBSD: fonts.mk,v 1.3.2.2 2003/02/18 17:51:09 jmmv Exp $
#
# This Makefile fragment is intended to be included by packages that install
# fonts (most of them in the fonts category).  It takes care of updating the
# fonts.dir files at install/deinstall time.
#
# The following variables need to be defined by packages using fonts.mk:
#
# FONTS_<TYPE>_DIRS - Whitespaced list of directories where the font database
#                     is updated. If empty, nothing is done for this TYPE.
#
# Supported TYPEs: TTF, TYPE1, X11.
#

.if !defined(FONTS_MK)
FONTS_MK=		# defined

# TrueType fonts
FONTS_TTF_DIRS?=
# Type1 fonts
FONTS_TYPE1_DIRS?=
# Generic X fonts (PCF, SNF, BDF)
FONTS_X11_DIRS?=

.if !empty(FONTS_TTF_DIRS) || !empty(FONTS_TYPE1_DIRS) || !empty(FONTS_X11_DIRS)

USE_PKGINSTALL=		YES
INSTALL_EXTRA_TMPL+=	${.CURDIR}/../../mk/install/fonts
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/../../mk/install/fonts

.if !empty(FONTS_TTF_DIRS)
EVAL_PREFIX+=			TTMKFDIR_PREFIX=ttmkfdir
TTMKFDIR_PREFIX_DEFAULT=	${LOCALBASE}
FILES_SUBST+=		FONTS_TTF="YES"
FILES_SUBST+=		FONTS_TTF_DIRS="${FONTS_TTF_DIRS}"
FILES_SUBST+=		TTMKFDIR="${TTMKFDIR_PREFIX}/bin/ttmkfdir"
DEPENDS+=		ttmkfdir>=0:../../fonts/ttmkfdir
.endif

.if !empty(FONTS_TYPE1_DIRS)
EVAL_PREFIX+=			TYPE1INST_PREFIX=type1inst
TYPE1INST_PREFIX_DEFAULT=	${LOCALBASE}
FILES_SUBST+=		FONTS_TYPE1="YES"
FILES_SUBST+=		FONTS_TYPE1_DIRS="${FONTS_TYPE1_DIRS}"
FILES_SUBST+=		TYPE1INST="${TYPE1INST_PREFIX}/bin/type1inst"
DEPENDS+=		type1inst>=0.6.1:../../fonts/type1inst
.endif

.if !empty(FONTS_X11_DIRS)
FILES_SUBST+=		FONTS_X11="YES"
FILES_SUBST+=		FONTS_X11_DIRS="${FONTS_X11_DIRS}"
FILES_SUBST+=		MKFONTDIR="${X11BASE}/bin/mkfontdir"
.endif

.endif

.endif	# FONTS_MK
