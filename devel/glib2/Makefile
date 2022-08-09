# $NetBSD: Makefile,v 1.290 2022/08/09 12:08:28 jperkin Exp $

.include "Makefile.common"

CATEGORIES=	devel gnome
COMMENT=	Some useful routines for C programming (glib2)

.include "options.mk"

MESON_ARGS+=	-Dinstalled_tests=false
# Avoid linux dependency on libmount-dev
MESON_ARGS+=	-Dlibmount=disabled
MESON_ARGS+=	-Dlocalstatedir=${VARBASE}
.if ${OPSYS} == "FreeBSD"
MESON_ARGS+=	-Db_lundef=false
.endif

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gio:${WRKSRC}/output/glib:${WRKSRC}/output/gobject:${WRKSRC}/output/gmodule
# For Darwin
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/gio:${WRKSRC}/output/glib:${WRKSRC}/output/gobject:${WRKSRC}/output/gmodule

CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -D__stub_epoll_create
LDFLAGS.SunOS+=		-lnsl -lsocket
LDFLAGS.FreeBSD+=	-liconv

.include "../../mk/bsd.prefs.mk"
.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
MESON_CROSS_ARCH_VARS+=			growing_stack
MESON_CROSS_OPSYS_VARS+=		have_c99_snprintf
MESON_CROSS_OPSYS_VARS+=		have_c99_vsnprintf
MESON_CROSS_OPSYS_VARS+=		have_strlcpy
MESON_CROSS_OPSYS_VARS+=		have_unix98_printf
MESON_CROSS.NetBSD.have_c99_snprintf=	true
MESON_CROSS.NetBSD.have_c99_vsnprintf=	true
MESON_CROSS.NetBSD.have_strlcpy=	true
MESON_CROSS.NetBSD.have_unix98_printf=	true
MESON_CROSS.hppa.growing_stack=		true
.endif

REPLACE_PYTHON+=	gio/gio-querymodules-wrapper.py
REPLACE_PYTHON+=	gio/tests/gengiotypefuncs.py
REPLACE_PYTHON+=	gio/tests/memory-monitor-dbus.py.in
REPLACE_PYTHON+=	gio/tests/memory-monitor-portal.py.in
REPLACE_PYTHON+=	gio/tests/static-link.py
REPLACE_PYTHON+=	glib/update-gtranslit.py
REPLACE_PYTHON+=	gobject/tests/mkenums.py
REPLACE_PYTHON+=	tests/gen-casefold-txt.py
REPLACE_PYTHON+=	tests/gen-casemap-txt.py

GIO_MODULES_DIR=	${PREFIX}/lib/gio/modules
OWN_DIRS=		${GIO_MODULES_DIR}

FILES_SUBST+=		GIO_MODULES_DIR=${GIO_MODULES_DIR}
FILES_SUBST+=		GIO_QUERYMODULES=${PREFIX}/bin/gio-querymodules
FILES_SUBST+=		GLIB_COMPILE_SCHEMAS=${PREFIX}/bin/glib-compile-schemas
FILES_SUBST+=		GLIB_SCHEMAS_DIR=${PREFIX}/share/glib-2.0/schemas

BUILD_DEFS+=		VARBASE

SUBST_CLASSES+=		xdg
SUBST_MESSAGE.xdg=	Adjust XDG_DATA_DIRS so schemas and pixbuf loaders are found
SUBST_STAGE.xdg=	pre-configure
SUBST_FILES.xdg=	glib/gcharset.c glib/gutils.c gio/xdgmime/xdgmime.c
SUBST_SED.xdg=		-e 's,/usr/local/share/:/usr/share/,${PREFIX}/share,'
SUBST_SED.xdg+=		-e 's,/etc/xdg,${PKG_SYSCONFDIR}/xdg,'
SUBST_SED.xdg+=		-e 's,/usr/share/locale,${PREFIX}/${PKGLOCALEDIR}/locale,'

PKGCONFIG_OVERRIDE+=	output/meson-private/gio-2.0.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gio-unix-2.0.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/glib-2.0.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gmodule-2.0.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gmodule-export-2.0.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gmodule-no-export-2.0.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gobject-2.0.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gthread-2.0.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

# to run gdbus-codegen to generate gdbus-daemon-generated.{h,c}
TOOL_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
PYTHON_FOR_BUILD_ONLY=	yes

post-extract:
	${CHMOD} +x ${WRKSRC}/gio/tests/gengiotypefuncs.py

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
