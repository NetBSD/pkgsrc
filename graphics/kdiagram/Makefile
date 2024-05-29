# $NetBSD: Makefile,v 1.7 2024/05/29 16:32:56 adam Exp $

DISTNAME=	kdiagram-2.8.0
PKGREVISION=	6
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE:=kdiagram/2.8.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kde.org/
COMMENT=	Powerful libraries for creating business diagrams
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	extra-cmake-modules>=5.60.0:../../devel/extra-cmake-modules

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DECM_MKSPECS_INSTALL_DIR=${QTDIR}/mkspecs/modules

.include "../../devel/cmake/build.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
