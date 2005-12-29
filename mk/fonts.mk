# $NetBSD: fonts.mk,v 1.9 2005/12/29 03:44:38 jlam Exp $
#
# XXX This file's use is deprecated.  This is here temporarily to help
# XXX packages transition to using the new fonts capability of the
# XXX pkginstall framework.
#

.if !defined(FONTS_MK)
FONTS_MK=		# defined

# Support the old FONTS_<TYPE>_DIRS variables for a while until we can
# nuke them. 
#
FONTS_DIRS.ttf+=	${FONTS_TTF_DIRS}
FONTS_DIRS.type1+=	${FONTS_TYPE1_DIRS}
FONTS_DIRS.x11+=	${FONTS_X11_DIRS}

USE_PKGINSTALL=		YES

.endif	# FONTS_MK
