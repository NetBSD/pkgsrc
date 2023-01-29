# $NetBSD: Makefile,v 1.26 2023/01/29 21:16:40 ryoon Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-icon-theme-${VERSION}
PKGREVISION=	3
CATEGORIES=	graphics

COMMENT=	Collection of icons used as the basis for MATE themes

ICON_THEMES=	yes

PKGCONFIG_OVERRIDE+=	mate-icon-theme.pc.in

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
