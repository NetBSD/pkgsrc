# $NetBSD: Makefile,v 1.13 2003/09/18 16:25:10 jmmv Exp $

PKGNAME=	ghostscript-${GS_VERS}
PKGREVISION=	4
COMMENT=	Aladdin Postscript interpreter

USE_X11=		YES
GS_DISPLAY_DEVICE=	x11.dev
XLIBS=			Xt SM ICE Xext X11

.include "../../print/ghostscript-nox11/Makefile.common"

MAKEFRAGS+=		${FILESDIR}/devs.x11
