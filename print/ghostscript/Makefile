# $NetBSD: Makefile,v 1.3 2000/05/10 15:40:16 jlam Exp $

PKGNAME=	ghostscript-${GS_VERS}
CATEGORIES+=	x11

CONFLICTS=	ghostscript{,-x11,-nox11}-[0-9]*

USE_X11=	# defined

# Build with the X11 display device drivers.
#
MAKE_ENV+=	USE_X11=1

.include "../../print/ghostscript-nox11/Makefile.common"
