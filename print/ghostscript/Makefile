# $NetBSD: Makefile,v 1.4 2001/02/12 14:13:57 fredb Exp $

PKGNAME=	ghostscript-${GS_VERS}

CONFLICTS=	ghostscript{,-x11,-nox11}-[0-9]*

USE_X11=	# defined

# Build with the X11 display device drivers.
#
MAKE_ENV+=	USE_X11=1

.include "../../print/ghostscript-nox11/Makefile.common"
