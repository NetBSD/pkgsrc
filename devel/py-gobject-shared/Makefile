# $NetBSD: Makefile,v 1.38 2014/05/05 00:47:46 ryoon Exp $

PKGNAME=		py-gobject-shared-2.28.6
PKGREVISION=		12

.include "../../devel/py-gobject/Makefile.common"

PYTHON_FOR_BUILD_ONLY=	yes
INSTALLATION_DIRS=	include/pygtk-2.0 lib/pkgconfig
# we do not really need py-cairo's pkg-config flags
# just some non-empty valid arguments so py-cairo is detected
# as found
CONFIGURE_ARGS+=	PYCAIRO_CFLAGS="`pkg-config --cflags cairo`"
CONFIGURE_ARGS+=	PYCAIRO_LIBS="`pkg-config --libs cairo`"

do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${PREFIX:Q}/include/pygtk-2.0
	${INSTALL_DATA} ${WRKSRC}/gobject/pygobject.h \
		${DESTDIR:Q}${PREFIX:Q}/include/pygtk-2.0
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${PREFIX:Q}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/pygobject-2.0.pc \
		${DESTDIR:Q}${PREFIX:Q}/lib/pkgconfig

.include "../../lang/python/application.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection=	gobject-introspection>=0.9.5
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_DEPMETHOD.cairo=	build
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
