# $NetBSD: Makefile,v 1.59 2009/04/08 16:56:53 drochner Exp $

DISTNAME=		scribus-1.3.3.12
PKGREVISION=		2
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scribus/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scribus.net/
COMMENT=		Publishing layout with graphical interface

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		xdg-1.4
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake perl pkg-config
PTHREAD_OPTS+=		require
SHLIBTOOL_OVERRIDE=	# empty
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-cairo
CONFIGURE_ARGS+=	--with-extra-includes=${PREFIX}/include
CONFIGURE_ARGS+=	--with-extra-libs=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR}
# XXX should work with other Python versions, but there are
# stupid assumptions in the configure script
PYTHON_VERSIONS_ACCEPTED=	25 24
CONFIGURE_ARGS+=	--with-pythondir=${PREFIX}
# XXX make an option
CONFIGURE_ARGS+=	--disable-cups

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
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
