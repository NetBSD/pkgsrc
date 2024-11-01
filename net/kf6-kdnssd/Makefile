# $NetBSD: Makefile,v 1.4 2024/11/01 00:53:08 wiz Exp $

DISTNAME=	kdnssd-${KF6VER}
PKGREVISION=	2
CATEGORIES=	net

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Abstraction to system DNSSD features
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
