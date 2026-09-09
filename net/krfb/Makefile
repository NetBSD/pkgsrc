# $NetBSD: Makefile,v 1.89 2026/09/09 08:11:15 markd Exp $

DISTNAME=	krfb-${KAPPSVER}
CATEGORIES=	net

HOMEPAGE=	https://apps.kde.org/krfb/
COMMENT=	KDE desktop sharing
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=5.19.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

LDFLAGS.SunOS+=	-lsocket -lnsl

CMAKE_CONFIGURE_ARGS+=	-DDISABLE_PIPEWIRE=ON

BUILDLINK_TRANSFORM+=	rm:-Wall
BUILDLINK_TRANSFORM+=	rm:-Werror=undef
BUILDLINK_TRANSFORM+=	rm:-Wformat-security
BUILDLINK_TRANSFORM+=	rm:-Wundef

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kf6-kstatusnotifieritem/buildlink3.mk"
.include "../../net/kf6-kdnssd/buildlink3.mk"
.include "../../net/libvncserver/buildlink3.mk"
.include "../../security/kf6-kwallet/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
