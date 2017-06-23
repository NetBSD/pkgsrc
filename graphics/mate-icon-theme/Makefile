# $NetBSD: Makefile,v 1.2 2017/06/23 17:18:23 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-icon-theme-${VERSION:R}.2
CATEGORIES=	graphics

COMMENT=	Collection of icons used as the basis for MATE themes

PKGCONFIG_OVERRIDE+=	mate-icon-theme.pc.in

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
