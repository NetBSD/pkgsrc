# $NetBSD: Makefile,v 1.1 2016/05/21 18:53:55 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-icon-theme-${MATE_VERSION}
CATEGORIES=	graphics

COMMENT=	Collection of icons used as the basis for MATE themes

PKGCONFIG_OVERRIDE+=	mate-icon-theme.pc.in

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
