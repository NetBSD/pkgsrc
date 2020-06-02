# $NetBSD: Makefile,v 1.37 2020/06/02 08:22:54 adam Exp $

DISTNAME=	kauth-${KF5VER}
PKGREVISION=	4
CATEGORIES=	security

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Abstraction to system policy and authentication features
LICENSE=	gnu-lgpl-v2.1

CONF_FILES+=	${PREFIX}/share/examples/kauth/org.kde.kf5auth.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.kf5auth.conf

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../security/polkit-qt5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
