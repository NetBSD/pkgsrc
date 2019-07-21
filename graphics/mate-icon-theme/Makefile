# $NetBSD: Makefile,v 1.13 2019/07/21 22:25:02 wiz Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-icon-theme-${VERSION:R}.1
PKGREVISION=	2
CATEGORIES=	graphics

COMMENT=	Collection of icons used as the basis for MATE themes

PKGCONFIG_OVERRIDE+=	mate-icon-theme.pc.in

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
