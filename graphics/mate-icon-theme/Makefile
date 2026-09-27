# $NetBSD: Makefile,v 1.42 2026/09/27 11:36:54 tnn Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-icon-theme-${VERSION:R}.0
PKGREVISION=	18
CATEGORIES=	graphics

COMMENT=	Collection of icons used as the basis for MATE themes

ICON_THEMES=	yes

PKGCONFIG_OVERRIDE+=	mate-icon-theme.pc.in

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
