# $NetBSD: Makefile,v 1.2 2024/05/29 16:34:15 adam Exp $

DISTNAME=	kwallet-6.2.1
#DISTNAME=	kwallet-${KF6VER}
PKGREVISION=	1
CATEGORIES=	security

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Secure and unified container for user passwords
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=${KF6VER}:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

LDFLAGS.SunOS+=	-lsocket

CMAKE_ARGS+=	-DBUILD_KWALLET_QUERY=OFF

# remove conflict with kwallet
post-install:
	rm ${DESTDIR}${PREFIX}/share/dbus-1/services/org.kde.kwalletd5.service

.include "../../lang/python/tool.mk"
.include "../../devel/kf6-kcolorscheme/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/qca2-qt6/buildlink3.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
