# $NetBSD: Makefile,v 1.55 2024/02/06 11:17:41 markd Exp $

DISTNAME=	kwalletmanager-${KAPPSVER}
CATEGORIES=	security

HOMEPAGE=	https://apps.kde.org/kwalletmanager5/
COMMENT=	KDE wallet manager
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

CMAKE_ARGS+=		-DKAUTH_DBUS_DIR=${PREFIX}/share/examples/kwalletmanager
INSTALLATION_DIRS+=	share/examples/kwalletmanager

USE_TOOLS+=	msgmerge

MAKE_DIRS+=	${PKG_SYSCONFDIR}/dbus-1/system.d
CONF_FILES+=	${PREFIX}/share/examples/kwalletmanager/org.kde.kcontrol.kcmkwallet5.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.kcontrol.kcmkwallet5.conf

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
