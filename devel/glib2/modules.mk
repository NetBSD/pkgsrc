# $NetBSD: modules.mk,v 1.2 2019/11/03 10:39:12 rillig Exp $
#
# This Makefile fragment is intended to be included by packages that install
# GIO modules.  It takes care of rebuilding the corresponding databases at
# (de)installation time.
#

.if !defined(GIO_MODULES_MK)
GIO_MODULES_MK=	# defined

GIO_QUERYMODULES=	${BUILDLINK_PREFIX.glib2}/bin/gio-querymodules

FILES_SUBST+=		GIO_MODULES_DIR=${GIO_MODULES_DIR:Q}
FILES_SUBST+=		GIO_QUERYMODULES=${GIO_QUERYMODULES:Q}
GIO_MODULES_DIR=	${BUILDLINK_PREFIX.glib2}/lib/gio/modules
INSTALL_TEMPLATES+=	../../devel/glib2/files/modules.tmpl
DEINSTALL_TEMPLATES+=	../../devel/glib2/files/modules.tmpl

TOOLS_NOOP+=	gio-querymodules

.include "../../devel/glib2/buildlink3.mk"

.endif			# GIO_MODULES_MK
