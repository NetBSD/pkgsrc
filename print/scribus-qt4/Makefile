# $NetBSD: Makefile,v 1.60 2018/11/14 22:22:20 kleink Exp $

DISTNAME=		scribus-1.4.3
PKGREVISION=		20
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scribus/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.scribus.net/
COMMENT=		Publishing layout with graphical interface

USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake perl pkg-config
PTHREAD_OPTS+=		require
SHLIBTOOL_OVERRIDE=	# empty
USE_CMAKE=	yes
CMAKE_ARGS+=	-DPNG_LIBRARY_RELEASE=${LOCALBASE}/lib
# XXX not yet
#CMAKE_ARGS+=	-DWANT_HUNSPELL:BOOL=ON

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 1.4.3

INSTALLATION_DIRS+=	share/pixmaps

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/icons/scribus.png \
		${DESTDIR}${PREFIX}/share/pixmaps

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../print/cups-base/buildlink3.mk"
.include "../../print/podofo/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libart+= libart>=2.3.19nb1
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc/hyphen/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
