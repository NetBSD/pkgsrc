# $NetBSD: Makefile,v 1.80 2012/10/02 17:11:52 tron Exp $

DISTNAME=		scribus-1.3.3.14
PKGREVISION=		9
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scribus/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scribus.net/
COMMENT=		Publishing layout with graphical interface
# plus exceptions for qt3 and Windows GDI+ linkage
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake perl pkg-config
PTHREAD_OPTS+=		require
SHLIBTOOL_OVERRIDE=	# empty
USE_CMAKE=	yes

LDFLAGS.DragonFly=	-lX11

CONFIGURE_ARGS+=	--enable-cairo
CONFIGURE_ARGS+=	--with-extra-includes=${PREFIX}/include
CONFIGURE_ARGS+=	--with-extra-libs=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR}
CONFIGURE_ARGS+=	--with-pythondir=${PREFIX}
# XXX make an option
CONFIGURE_ARGS+=	--disable-cups

INSTALLATION_DIRS+=	share/pixmaps

post-install:
	${INSTALL_DATA} ${WRKSRC}/scribus/icons/scribus.png \
		${DESTDIR}${PREFIX}/share/pixmaps

.include "../../print/cups/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
BUILDLINK_API_DEPENDS.libart+= libart>=2.3.19nb1
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
