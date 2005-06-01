# $NetBSD: Makefile,v 1.15 2005/06/01 18:03:09 jlam Exp $

PKGNAME=	ghostscript-${GS_VERS}
PKGREVISION=	5
COMMENT=	Aladdin Postscript interpreter

GS_DISPLAY_DEVICE=	x11.dev
XLIBS=			Xt SM ICE Xext X11

.include "../../mk/x11.buildlink3.mk"
.include "../../print/ghostscript-nox11/Makefile.common"

MAKEFRAGS+=		${FILESDIR}/devs.x11
