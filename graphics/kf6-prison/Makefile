# $NetBSD: Makefile,v 1.1 2024/05/26 12:26:50 markd Exp $

DISTNAME=	prison-${KF6VER}
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Barcode API to produce QRCode barcodes and DataMatrix barcodes
LICENSE=	mit

.include "../../meta-pkgs/kde/kf6.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=${KF6VER}:../../devel/kf6-kdoctools

USE_TOOLS+=	pkg-config

.include "../../converters/qrencode/buildlink3.mk"
.include "../../graphics/libdmtx/buildlink3.mk"
.include "../../graphics/zxing-cpp/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
