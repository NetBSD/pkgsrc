# $NetBSD: Makefile,v 1.126 2024/05/16 06:15:29 wiz Exp $

DISTNAME=	qpdfview-0.4.18
PKGREVISION=	43
CATEGORIES=	print
MASTER_SITES=	https://launchpad.net/qpdfview/trunk/${PKGVERSION_NOREV}/+download/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://launchpad.net/qpdfview
COMMENT=	Tabbed PDF viewer
LICENSE=	gnu-gpl-v2

DEPENDS+=	poppler-data-[0-9]*:../../print/poppler-data

USE_LANGUAGES=	c c++17
GCC_REQD+=	8 # std::optional
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} PKGMANDIR=${PKGMANDIR} \
		${QTDIR}/bin/qmake qpdfview.pro

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
