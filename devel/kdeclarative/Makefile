# $NetBSD: Makefile,v 1.15 2017/11/30 16:45:02 adam Exp $

DISTNAME=	kdeclarative-${KF5VER}
PKGREVISION=	11
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Provides integration of QML and KDE Frameworks
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_TOOLS+=	msgfmt

.include "../../meta-pkgs/kf5/Makefile.common"

.include "../../devel/kio/buildlink3.mk"
.include "../../devel/kpackage/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
