# $NetBSD: Makefile,v 1.36 2018/11/14 22:22:11 kleink Exp $

DISTNAME=	kdnssd-${KF5VER}
PKGREVISION=	4
CATEGORIES=	net

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Abstraction to system DNSSD features
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../net/avahi/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
