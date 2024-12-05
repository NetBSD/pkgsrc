# $NetBSD: Makefile,v 1.7 2024/12/05 09:43:24 markd Exp $

DISTNAME=	kdnssd-${KF6VER}
CATEGORIES=	net

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Abstraction to system DNSSD features
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
