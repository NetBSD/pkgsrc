# $NetBSD: Makefile,v 1.1 2016/05/26 08:43:53 markd Exp $

DISTNAME=	kimageformats-${KF5VER}
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Image format plugins for Qt5
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	pkg-config

.include "../../archivers/karchive/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
