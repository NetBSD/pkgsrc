# $NetBSD: Makefile,v 1.1.1.1 2000/05/07 02:05:23 jlam Exp $

PKGNAME=	ghostscript-x11-${GS_VERS}
CATEGORIES+=	x11

CONFLICTS=	ghostscript{,-nox11}-[0-9]*

USE_X11=	# defined

# Build with the X11 display device drivers.
#
MAKE_ENV+=	USE_X11=1

.include "../../print/ghostscript-nox11/Makefile.common"
