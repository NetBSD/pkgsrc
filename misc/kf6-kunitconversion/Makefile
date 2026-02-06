# $NetBSD: Makefile,v 1.12 2026/02/06 10:05:20 wiz Exp $

DISTNAME=	kunitconversion-${KF6VER}
PKGREVISION=	3
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for unit conversion
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

CMAKE_CONFIGURE_ARGS+=	-DBUILD_PYTHON_BINDINGS=OFF

USE_TOOLS+=		msgmerge

#.include "../../lang/python/tool.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
