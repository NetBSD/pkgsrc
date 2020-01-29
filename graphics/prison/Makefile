# $NetBSD: Makefile,v 1.15 2020/01/29 11:49:26 markd Exp $

DISTNAME=	prison-${KF5VER}
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Barcode API to produce QRCode barcodes and DataMatrix barcodes
LICENSE=	mit

.include "../../meta-pkgs/kde/kf5.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	pkg-config

.include "../../converters/qrencode/buildlink3.mk"
.include "../../graphics/libdmtx/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
