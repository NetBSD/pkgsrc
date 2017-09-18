# $NetBSD: Makefile,v 1.6 2017/09/18 09:53:22 maya Exp $

DISTNAME=	breeze-icons-${KF5VER}
PKGREVISION=	5
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Breeze icon themes
LICENSE=	gnu-lgpl-v2.1 AND gnu-lgpl-v3

.include "../../meta-pkgs/kf5/Makefile.common"

BUILDLINK_DEPMETHOD.qt5-qtbase= build
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
