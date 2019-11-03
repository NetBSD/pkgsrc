# $NetBSD: schemas.mk,v 1.3 2019/11/03 10:39:12 rillig Exp $
#
# This Makefile fragment is intended to be included by packages that install
# GSettings schemas.  It takes care of rebuilding the corresponding databases
# at (de)installation time.
#

.if !defined(GLIB_SCHEMAS_MK)
GLIB_SCHEMAS_MK=	# defined

GLIB_COMPILE_SCHEMAS=	${BUILDLINK_PREFIX.glib2}/bin/glib-compile-schemas

FILES_SUBST+=		GLIB_SCHEMAS_DIR=${GLIB_SCHEMAS_DIR:Q}
FILES_SUBST+=		GLIB_COMPILE_SCHEMAS=${GLIB_COMPILE_SCHEMAS:Q}
GLIB_SCHEMAS_DIR=	${BUILDLINK_PREFIX.glib2}/share/glib-2.0/schemas
INSTALL_TEMPLATES+=	../../devel/glib2/files/schemas.tmpl
DEINSTALL_TEMPLATES+=	../../devel/glib2/files/schemas.tmpl

TOOLS_NOOP+=		glib-compile-schemas
# Adding glib-compile-schemas to TOOLS_NOOP is not enough to mock out all
# calls to this tool.  Some packages do 'pkg-config --variable
# glib_compile_schemas gio-2.0' to get the path to the binary.  Do a best
# effort here by overriding the possibly-defined GLIB_COMPILE_SCHEMAS
# variable in the offending Makefiles.
MAKE_FLAGS+=		GLIB_COMPILE_SCHEMAS=glib-compile-schemas

.include "../../devel/glib2/buildlink3.mk"

.endif			# GLIB_SCHEMAS_MK
