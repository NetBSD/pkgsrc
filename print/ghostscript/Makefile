# $NetBSD: Makefile,v 1.5 2001/02/17 17:51:41 wiz Exp $

PKGNAME=	ghostscript-${GS_VERS}

COMMENT=	Aladdin Postscript interpreter with X11 drivers

CONFLICTS=	ghostscript{,-x11,-nox11}-[0-9]*

USE_X11=	# defined

# Build with the X11 display device drivers.
#
MAKE_ENV+=	USE_X11=1

.include "../../print/ghostscript-nox11/Makefile.common"
