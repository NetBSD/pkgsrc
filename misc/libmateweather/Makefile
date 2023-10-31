# $NetBSD: Makefile,v 1.46 2023/10/31 00:14:53 gutteridge Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	libmateweather-${VERSION:R}.2
CATEGORIES=	misc

COMMENT=	Weather information access library

PKGCONFIG_OVERRIDE+=	libmateweather/mateweather.pc.in

.include "../../devel/glib2/schemas.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
