# $NetBSD: Makefile,v 1.31 2012/10/02 17:10:51 tron Exp $

PKGNAME=		py-gobject-shared-2.28.6
PKGREVISION=		6

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/py-gobject/Makefile.common"

PYTHON_FOR_BUILD_ONLY=	yes
INSTALLATION_DIRS=	include/pygtk-2.0 lib/pkgconfig

do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${PREFIX:Q}/include/pygtk-2.0
	${INSTALL_DATA} ${WRKSRC}/gobject/pygobject.h \
		${DESTDIR:Q}${PREFIX:Q}/include/pygtk-2.0
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${PREFIX:Q}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/pygobject-2.0.pc \
		${DESTDIR:Q}${PREFIX:Q}/lib/pkgconfig

.include "../../lang/python/application.mk"
BUILDLINK_DEPMETHOD.pycairo=	build
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection=	gobject-introspection>=0.9.5
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
