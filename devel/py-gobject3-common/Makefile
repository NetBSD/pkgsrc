# $NetBSD: Makefile,v 1.3 2014/07/06 13:52:02 ryoon Exp $

PYTHON_FOR_BUILD_ONLY=	yes

.include "../../devel/py-gobject3/Makefile.common"

PKGNAME=	py-gobject3-common-${VER}

COMMENT=	Python version independent files for glib2 gobject bindings

CONFIGURE_ARGS+=	--disable-cairo

do-build:

INSTALLATION_DIRS+=	include/pygobject-3.0 lib/pkgconfig

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gi/pygobject.h \
		${DESTDIR}${PREFIX}/include/pygobject-3.0/pygobject.h
	${INSTALL_SCRIPT} ${WRKSRC}/pygobject-3.0.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig/pygobject-3.0.pc

.include "../../mk/bsd.pkg.mk"
