# $NetBSD: Makefile,v 1.60 2023/01/29 21:17:28 ryoon Exp $

DISTNAME=	krfb-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	net

HOMEPAGE=	https://apps.kde.org/krfb/
COMMENT=	KDE desktop sharing
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/kdnssd/buildlink3.mk"
.include "../../net/libvncserver/buildlink3.mk"
.include "../../security/kwallet/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
