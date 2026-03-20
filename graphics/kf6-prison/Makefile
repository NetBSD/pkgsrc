# $NetBSD: Makefile,v 1.15 2026/03/20 22:14:27 markd Exp $

DISTNAME=	prison-${KF6VER}
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Barcode API to produce QRCode barcodes and DataMatrix barcodes
LICENSE=	mit

# Temporarily expand out kde/kf6.mk
#.include "../../meta-pkgs/kde/kf6.mk"
KF6VER=6.24.0
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${KF6VER:R}/}
EXTRACT_SUFX=	.tar.xz
PKGNAME?=	kf6-${DISTNAME}

.include "../../devel/extra-cmake-modules/buildlink3.mk"

CMAKE_CONFIGURE_ARGS+=	-DKF_IGNORE_PLATFORM_CHECK=true

USE_CXX_FEATURES+=	c++20

.include "../../meta-pkgs/kde/Makefile.common"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
#TOOL_DEPENDS+=	kf6-kdoctools>=${KF6VER}:../../devel/kf6-kdoctools

USE_TOOLS+=	pkg-config

.include "../../converters/qrencode/buildlink3.mk"
.include "../../graphics/libdmtx/buildlink3.mk"
.include "../../graphics/zxing-cpp/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
