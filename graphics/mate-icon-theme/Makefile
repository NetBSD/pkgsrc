# $NetBSD: Makefile,v 1.29 2023/11/12 13:22:08 wiz Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-icon-theme-${VERSION:R}.0
PKGREVISION=	5
CATEGORIES=	graphics

COMMENT=	Collection of icons used as the basis for MATE themes

ICON_THEMES=	yes

PKGCONFIG_OVERRIDE+=	mate-icon-theme.pc.in

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
