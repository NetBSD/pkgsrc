# $NetBSD: Makefile,v 1.3 2023/10/31 19:56:51 adam Exp $

DISTNAME=	qtwayland-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtwayland-${QTVERSION}
COMMENT=	Qt6 wayland
CATEGORIES=	devel
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../devel/wayland/platform.mk"

.if ${PLATFORM_SUPPORTS_WAYLAND:tl} == no
PKG_SKIP_REASON+=	"Platform does not support Wayland"
.endif

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6WaylandClient.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6WaylandCompositor.pc

.include "../../devel/wayland/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
