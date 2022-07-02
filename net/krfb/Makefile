# $NetBSD: Makefile,v 1.53 2022/07/02 16:53:33 ryoon Exp $

DISTNAME=	krfb-${KAPPSVER}
PKGREVISION=	9
CATEGORIES=	net

HOMEPAGE=	https://kde.org/applications/system/krfb/
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
