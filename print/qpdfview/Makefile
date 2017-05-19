# $NetBSD: Makefile,v 1.43 2017/05/19 13:29:04 prlw1 Exp $

VER=		0.4.16
DISTNAME=	qpdfview-${VER}
PKGREVISION=	11
CATEGORIES=	print
MASTER_SITES=	https://launchpad.net/qpdfview/trunk/${VER}/+download/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://launchpad.net/qpdfview
COMMENT=	Tabbed PDF viewer
LICENSE=	gnu-gpl-v2

DEPENDS+=	poppler-data-[0-9]*:../../print/poppler-data
DEPENDS+=	qt4-sqlite3-[0-9]*:../../x11/qt4-sqlite3

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

INSTALL_MAKE_FLAGS+=    INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} PKGMANDIR=${PKGMANDIR} \
		${QTDIR}/bin/qmake qpdfview.pro

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
