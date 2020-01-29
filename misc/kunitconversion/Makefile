# $NetBSD: Makefile,v 1.21 2020/01/29 11:49:26 markd Exp $

DISTNAME=	kunitconversion-${KF5VER}
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for unit conversion
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

.include "../../lang/python/tool.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
