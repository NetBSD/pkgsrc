# $NetBSD: Makefile,v 1.2 2018/02/07 15:35:10 jperkin Exp $

DISTNAME=	prison-${KF5VER}
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Barcode API to produce QRCode barcodes and DataMatrix barcodes
LICENSE=	mit

.include "../../meta-pkgs/kf5/Makefile.common"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	pkg-config

#SUBST_CLASSES+=		xdg
#SUBST_STAGE.xdg=	pre-configure
#SUBST_MESSAGE.xdg=	Install via examples dir.
#SUBST_FILES.xdg=	CMakeLists.txt
#SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_DATAROOTDIR}/examples/kde-xdg:'

#MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
#CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/prison.categories \
#		${PKG_SYSCONFDIR}/xdg/prison.categories

.include "../../converters/qrencode/buildlink3.mk"
.include "../../graphics/libdmtx/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
