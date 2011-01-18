# $NetBSD: schemas.mk,v 1.1 2011/01/18 10:03:59 jmmv Exp $
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
GLIB_SCHEMAS_DIR=${BUILDLINK_PREFIX.glib2}/share/glib-2.0/schemas
INSTALL_TEMPLATES+=	../../devel/glib2/files/schemas.tmpl
DEINSTALL_TEMPLATES+=	../../devel/glib2/files/schemas.tmpl

TOOLS_NOOP+=		glib-compile-schemas

.include "../../devel/glib2/buildlink3.mk"

.endif			# GLIB_SCHEMAS_MK
