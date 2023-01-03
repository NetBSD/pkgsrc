# $NetBSD: Makefile,v 1.25 2023/01/03 17:37:26 wiz Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-icon-theme-${VERSION}
PKGREVISION=	2
CATEGORIES=	graphics

COMMENT=	Collection of icons used as the basis for MATE themes

ICON_THEMES=	yes

PKGCONFIG_OVERRIDE+=	mate-icon-theme.pc.in

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
