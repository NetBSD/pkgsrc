# $NetBSD: Makefile,v 1.1 2014/02/12 00:57:25 prlw1 Exp $

.include "../../devel/py-gobject3/Makefile.common"

PKGNAME=	py-gobject3-common-${VER}

COMMENT=	Python version independent files for glib2 gobject bindings

do-build:

INSTALLATION_DIRS+=	include/pygobject-3.0 lib/pkgconfig

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gi/_gobject/pygobject.h \
		${DESTDIR}${PREFIX}/include/pygobject-3.0/pygobject.h
	${INSTALL_SCRIPT} ${WRKSRC}/pygobject-3.0.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig/pygobject-3.0.pc

.include "../../mk/bsd.pkg.mk"
