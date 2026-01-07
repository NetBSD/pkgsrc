# $NetBSD: Makefile,v 1.87 2026/01/07 08:48:20 wiz Exp $

DISTNAME=	krdc-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	net

HOMEPAGE=	https://kde.org/applications/internet/krdc/
COMMENT=	KDE remote desktop client
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

# Until freerdp3 works
CMAKE_CONFIGURE_ARGS+=	-DWITH_RDP=OFF

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kf6-kstatusnotifieritem/buildlink3.mk"
#.include "../../net/freerdp2/buildlink3.mk"
.include "../../net/kf6-kdnssd/buildlink3.mk"
.include "../../net/libvncserver/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
