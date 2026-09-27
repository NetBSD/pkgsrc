# $NetBSD: Makefile,v 1.18 2026/09/27 11:38:04 tnn Exp $

DISTNAME=	kdnssd-${KF6VER}
PKGREVISION=	1
CATEGORIES=	net

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Abstraction to system DNSSD features
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
