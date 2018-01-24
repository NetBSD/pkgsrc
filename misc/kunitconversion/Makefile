# $NetBSD: Makefile,v 1.9 2018/01/24 19:06:09 markd Exp $

DISTNAME=	kunitconversion-${KF5VER}
PKGREVISION=	1
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for unit conversion
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

.include "../../lang/python/tool.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
