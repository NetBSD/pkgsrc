# $NetBSD: Makefile,v 1.271 2020/04/08 12:22:10 prlw1 Exp $

.include "Makefile.common"

PKGREVISION=	1
CATEGORIES=	devel gnome
COMMENT=	Some useful routines for C programming (glib2)

.include "options.mk"

MESON_ARGS+=	-Dinstalled_tests=false
# Avoid linux dependency on libmount-dev
MESON_ARGS+=	-Dlibmount=disabled

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gio:${WRKSRC}/output/glib:${WRKSRC}/output/gobject:${WRKSRC}/output/gmodule

CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600 -D__EXTENSIONS__
LDFLAGS.SunOS+=		-liconv -lintl -lnsl -lsocket
LDFLAGS.FreeBSD+=	-liconv

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
SUBST_CLASSES+=		dbusdb
SUBST_MESSAGE.dbusdb=	Adjust dbus machine uuid path to dbus package
SUBST_STAGE.dbusdb=	pre-configure
SUBST_FILES.dbusdb=	gio/gdbusconnection.c
SUBST_FILES.dbusdb+=	gio/gdbusprivate.c
SUBST_FILES.dbusdb+=	po/*.po
SUBST_SED.dbusdb=	-e 's,/var/lib/dbus,${VARBASE}/db/dbus,g'

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
.include "../../mk/bsd.pkg.mk"
