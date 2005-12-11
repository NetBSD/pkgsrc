# $NetBSD: Makefile,v 1.15.4.1 2005/12/11 12:04:26 seb Exp $

PKGNAME=	ghostscript-${GS_VERS}
PKGREVISION=	6
COMMENT=	Aladdin Postscript interpreter

GS_DISPLAY_DEVICE=	x11.dev
XLIBS=			Xt SM ICE Xext X11

.include "../../mk/x11.buildlink3.mk"
.include "../../print/ghostscript-nox11/Makefile.common"

MAKEFRAGS+=		${FILESDIR}/devs.x11
