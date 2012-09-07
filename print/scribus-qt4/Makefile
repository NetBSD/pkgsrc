# $NetBSD: Makefile,v 1.13 2012/09/07 19:17:26 adam Exp $

DISTNAME=		scribus-1.4.1
PKGREVISION=		2
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scribus/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scribus.net/
COMMENT=		Publishing layout with graphical interface

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/Scribus
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake perl pkg-config
PTHREAD_OPTS+=		require
SHLIBTOOL_OVERRIDE=	# empty
USE_CMAKE=	yes
CMAKE_ARGS+=	-DPNG_LIBRARY_RELEASE=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--enable-cairo
CONFIGURE_ARGS+=	--with-extra-includes=${PREFIX}/include
CONFIGURE_ARGS+=	--with-extra-libs=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR}
CONFIGURE_ARGS+=	--with-pythondir=${PREFIX}
# XXX make an option
CONFIGURE_ARGS+=	--disable-cups

INSTALLATION_DIRS+=	share/pixmaps

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/icons/scribus.png \
		${DESTDIR}${PREFIX}/share/pixmaps

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../print/podofo/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libart+= libart>=2.3.19nb1
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
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
