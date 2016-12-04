# $NetBSD: Makefile,v 1.2 2016/12/04 05:17:28 ryoon Exp $

DISTNAME=	breeze-icons-${KF5VER}
PKGREVISION=	1
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Breeze icon themes
LICENSE=	gnu-lgpl-v2.1 AND gnu-lgpl-v3

.include "../../meta-pkgs/kf5/Makefile.common"

BUILDLINK_DEPMETHOD.qt5-qtbase= build
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
