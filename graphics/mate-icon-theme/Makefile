# $NetBSD: Makefile,v 1.8 2018/11/14 22:21:43 kleink Exp $

PKGREVISION= 2
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-icon-theme-${VERSION}
CATEGORIES=	graphics

COMMENT=	Collection of icons used as the basis for MATE themes

PKGCONFIG_OVERRIDE+=	mate-icon-theme.pc.in

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
