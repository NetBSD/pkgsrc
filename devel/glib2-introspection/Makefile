# $NetBSD: Makefile,v 1.5 2026/09/02 19:01:26 wiz Exp $

PKGREVISION= 1
.include "../../devel/glib2/Makefile.common"

PKGNAME=	glib2-introspection-${DISTNAME:S/^glib-//}
CATEGORIES=	devel gnome

COMMENT=	Introspection data for glib2

TOOL_DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	glib2>=2.88.1:../../devel/glib2

CONFLICTS+=	gobject-introspection<1.86.0nb2

MESON_ARGS+=	-Ddtrace=disabled
MESON_ARGS+=	-Dglib_debug=disabled
MESON_ARGS+=	-Dintrospection=enabled
MESON_ARGS+=	-Dinstalled_tests=false
MESON_ARGS+=	-Dlibmount=disabled
MESON_ARGS+=	-Dlocalstatedir=${VARBASE}
MESON_ARGS+=	-Druntime_dir=${VARBASE}/run

.include "../../mk/bsd.prefs.mk"

.if !empty(PKG_OPTIONS.glib2:Mcocoa)
MESON_ARGS+=	-Duse_cocoa=true
.endif

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/girepository:${WRKSRC}/output/gio:${WRKSRC}/output/glib:${WRKSRC}/output/gobject:${WRKSRC}/output/gmodule:${WRKSRC}/output/gthread
# For Darwin
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/girepository:${WRKSRC}/output/gio:${WRKSRC}/output/glib:${WRKSRC}/output/gobject:${WRKSRC}/output/gmodule:${WRKSRC}/output/gthread

PATCHDIR=	${.CURDIR}/../../devel/glib2/patches
DISTINFO_FILE=	${.CURDIR}/../../devel/glib2/distinfo

SUBST_CLASSES+=		meson
SUBST_STAGE.meson=	pre-configure
SUBST_FILES.meson+=	meson.build
SUBST_MESSAGE.meson=	Forcing meson to find proper Python.
SUBST_VARS.meson+=	PYTHONBIN

SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Replace PYTHON.
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	glib/gtester-report.in
SUBST_SED.python=	-e 's,@PYTHON@,${PYTHONBIN},'

SUBST_CLASSES+=		libdirs
SUBST_STAGE.libdirs=	pre-configure
SUBST_FILES.libdirs+=	girepository/gitypelib.c
SUBST_VARS.libdirs+=	PREFIX

GIR_TARGETS+=		girepository/introspection/GIRepository-3.0.gir
GIR_TARGETS+=		girepository/introspection/GLib-2.0.gir
GIR_TARGETS+=		girepository/introspection/GLibUnix-2.0.gir
GIR_TARGETS+=		girepository/introspection/GModule-2.0.gir
GIR_TARGETS+=		girepository/introspection/GObject-2.0.gir
GIR_TARGETS+=		girepository/introspection/Gio-2.0.gir
GIR_TARGETS+=		girepository/introspection/GioUnix-2.0.gir
TYPELIB_TARGETS+=	girepository/introspection/GIRepository-3.0.typelib
TYPELIB_TARGETS+=	girepository/introspection/GLib-2.0.typelib
TYPELIB_TARGETS+=	girepository/introspection/GLibUnix-2.0.typelib
TYPELIB_TARGETS+=	girepository/introspection/GModule-2.0.typelib
TYPELIB_TARGETS+=	girepository/introspection/GObject-2.0.typelib
TYPELIB_TARGETS+=	girepository/introspection/Gio-2.0.typelib
TYPELIB_TARGETS+=	girepository/introspection/GioUnix-2.0.typelib

MESON_BUILD_TARGET=	${GIR_ARGETS} ${TYPELIB_TARGETS}
MESON_INSTALL=		no

INSTALLATION_DIRS=	lib/girepository-1.0 share/gir-1.0

# avoid mixture of headers from ${PREFIX} and the source code itself
pre-configure:
	${RM} -rf ${BUILDLINK_DIR}/include/glib-2.0

do-install:
.for f in ${GIR_TARGETS}
	${INSTALL_DATA} ${WRKSRC}/output/${f} ${DESTDIR}${PREFIX}/share/gir-1.0/
.endfor
.for f in ${TYPELIB_TARGETS}
	${INSTALL_DATA} ${WRKSRC}/output/${f} ${DESTDIR}${PREFIX}/lib/girepository-1.0/
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.86.0nb3
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
