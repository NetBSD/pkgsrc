# $NetBSD: Makefile,v 1.182 2011/04/21 10:27:35 roy Exp $

.include "Makefile.common"

PKGREVISION=		2

CATEGORIES=		devel

COMMENT=		Some useful routines for C programming (glib2)

USE_TOOLS+=		msgfmt perl:run

PKGCONFIG_OVERRIDE=	glib-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	glib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-export-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-no-export-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-no-export-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gobject-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gobject-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gthread-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gthread-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gio-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gio-unix-2.0.pc.in

FILES_SUBST+=		GIO_MODULES_DIR=${PREFIX}/lib/gio/modules
FILES_SUBST+=		GIO_QUERYMODULES=${PREFIX}/bin/gio-querymodules
FILES_SUBST+=		GLIB_COMPILE_SCHEMAS=${PREFIX}/bin/glib-compile-schemas
FILES_SUBST+=		GLIB_SCHEMAS_DIR=${PREFIX}/share/glib-2.0/schemas

# gtester is the glib unit testing and reporting framework
# agc doesn't want glib2 to depend on python so we install it
# in a broken and useless state.
CHECK_INTERPRETER_SKIP+=	bin/gtester-report

# need pcre utf8 + unicode-properties
BUILDLINK_API_DEPENDS.pcre+=	pcre>=8.11

LIBS.SunOS+=	-lnsl -lsocket

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
