# $NetBSD: Makefile,v 1.14 2005/05/30 14:57:28 dillo Exp $

PKGNAME=	ghostscript-${GS_VERS}
PKGREVISION=	5
COMMENT=	Aladdin Postscript interpreter

USE_X11=		YES
GS_DISPLAY_DEVICE=	x11.dev
XLIBS=			Xt SM ICE Xext X11

.include "../../print/ghostscript-nox11/Makefile.common"

MAKEFRAGS+=		${FILESDIR}/devs.x11
