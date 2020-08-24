# $NetBSD: Makefile,v 1.19 2020/08/24 04:41:39 gutteridge Exp $

PKGREVISION= 2
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-icon-theme-${VERSION:R}.0
CATEGORIES=	graphics

COMMENT=	Collection of icons used as the basis for MATE themes

PKGCONFIG_OVERRIDE+=	mate-icon-theme.pc.in

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
