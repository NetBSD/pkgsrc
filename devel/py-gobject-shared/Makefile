# $NetBSD: Makefile,v 1.50 2023/11/27 15:06:25 jperkin Exp $

PKGNAME=	py-${DISTNAME:S/^py//:S/-/-shared-/1}
PKGREVISION=	10

.include "../../devel/py-gobject/Makefile.common"

NO_BUILD=		yes
PYTHON_FOR_BUILD_ONLY=	yes
INSTALLATION_DIRS=	include/pygtk-2.0 lib/pkgconfig
# we do not really need py-cairo's pkg-config flags
# just some non-empty valid arguments so py-cairo is detected
# as found
CONFIGURE_ARGS+=	PYCAIRO_CFLAGS="`pkg-config --cflags cairo`"
CONFIGURE_ARGS+=	PYCAIRO_LIBS="`pkg-config --libs cairo`"

#	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/pygtk-2.0
#	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/pkgconfig
do-install:
	${INSTALL_DATA} ${WRKSRC}/glib/pyglib.h \
		${DESTDIR}${PREFIX}/include/pygtk-2.0
	${INSTALL_DATA} ${WRKSRC}/gobject/pygobject.h \
		${DESTDIR}${PREFIX}/include/pygtk-2.0
	${INSTALL_DATA} ${WRKSRC}/pygobject-2.0.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

BUILDLINK_API_DEPENDS.gobject-introspection=	gobject-introspection>=0.9.5
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_DEPMETHOD.cairo=	build
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
