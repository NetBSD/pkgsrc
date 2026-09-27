# $NetBSD: Makefile,v 1.24 2026/09/27 11:36:49 tnn Exp $

DISTNAME=	kdiagram-3.0.1
PKGREVISION=	5
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE:=kdiagram/3.0.1/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kde.org/
COMMENT=	Powerful libraries for creating business diagrams
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DECM_MKSPECS_INSTALL_DIR=${QTDIR}/mkspecs/modules

.include "../../devel/cmake/build.mk"

.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
