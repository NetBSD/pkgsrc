# $NetBSD: Makefile,v 1.207 2012/07/11 23:07:06 marino Exp $

.include "Makefile.common"
.include "options.mk"

PKGREVISION=		1

CATEGORIES=		devel

COMMENT=		Some useful routines for C programming (glib2)

USE_TOOLS+=		msgfmt perl:run

PKGCONFIG_OVERRIDE+=	glib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-export-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-no-export-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gobject-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gthread-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gio-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gio-unix-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gio-windows-2.0.pc.in

FILES_SUBST+=		GIO_MODULES_DIR=${PREFIX}/lib/gio/modules
FILES_SUBST+=		GIO_QUERYMODULES=${PREFIX}/bin/gio-querymodules
FILES_SUBST+=		GLIB_COMPILE_SCHEMAS=${PREFIX}/bin/glib-compile-schemas
FILES_SUBST+=		GLIB_SCHEMAS_DIR=${PREFIX}/share/glib-2.0/schemas

# gtester is the glib unit testing and reporting framework
# agc doesn't want glib2 to depend on python so we install it
# in a broken and useless state.
CHECK_INTERPRETER_SKIP+=	bin/gtester-report
CHECK_INTERPRETER_SKIP+=	bin/gdbus-codegen

# need pcre utf8 + unicode-properties
BUILDLINK_API_DEPENDS.pcre+=	pcre>=8.11
# to avoid pkg-config dependency, explicitly specify pcre location
CONFIGURE_ARGS+=	PCRE_CFLAGS=-I${BUILDLINK_PREFIX.pcre}/include
CONFIGURE_ARGS+=	PCRE_LIBS="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pcre}/lib -L${BUILDLINK_PREFIX.pcre}/lib -lpcre"

# needs gz_header structure
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.2.1

LIBS.SunOS+=		-lnsl -lsocket
CPPFLAGS.SunOS+=	-DBSD_COMP

.if ${OBJECT_FMT} == "ELF"
. if ${OPSYS} == "SunOS"
.  if ${MACHINE_ARCH} == "i386"
# _ILP32 Solaris machines emit "Large files are not supported by libelf" from
# /usr/include/libelf when _FILE_OFFSET_BITS=64, the value configure will set by itself
CONFIGURE_ARGS+=	ac_cv_sys_file_offset_bits=32
.  endif
. else
.include "../../devel/libelf/buildlink3.mk"
. endif
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
