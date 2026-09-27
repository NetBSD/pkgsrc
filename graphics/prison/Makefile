# $NetBSD: Makefile,v 1.58 2026/09/27 11:36:58 tnn Exp $

DISTNAME=	prison-${KF5VER}
PKGREVISION=	12
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Barcode API to produce QRCode barcodes and DataMatrix barcodes
LICENSE=	mit

.include "../../meta-pkgs/kde/kf5.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	pkg-config

.include "../../converters/qrencode/buildlink3.mk"
.include "../../graphics/libdmtx/buildlink3.mk"
# does not support zxing-cpp 3.x
#.include "../../graphics/zxing-cpp/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
