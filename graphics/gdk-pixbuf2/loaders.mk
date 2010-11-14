# $NetBSD: loaders.mk,v 1.1 2010/11/14 20:11:41 drochner Exp $
#
# This Makefile fragment is intended to be included by packages that install
# GTK2 modules.  It takes care of rebuilding the corresponding databases at
# (de)installation time.
#
# The following variables can be defined:
#    GTK2_LOADERS   - Set to YES if the package installs pixbuf loaders.
#

.if !defined(GTK2_LOADERS_MK)
GTK2_LOADERS_MK=	# defined

.if defined(_BUILDING_GTK2)
BUILDLINK_PREFIX.gdk-pixbuf2=	${PREFIX}
GTK2_LOADERS=		YES
.endif

GDK_PIXBUF_QUERY_LOADERS= \
 ${BUILDLINK_PREFIX.gdk-pixbuf2}/bin/gdk-pixbuf-query-loaders

.if defined(GTK2_LOADERS) && !empty(GTK2_LOADERS:M[Yy][Ee][Ss])
GDK_PIXBUF_LOADERS_DB= \
 ${BUILDLINK_PREFIX.gdk-pixbuf2}/lib/gdk-pixbuf-2.0/2.10.0/loaders.cache
FILES_SUBST+= GDK_PIXBUF_LOADERS_DB=${GDK_PIXBUF_LOADERS_DB:Q}
FILES_SUBST+= GDK_PIXBUF_QUERY_LOADERS=${GDK_PIXBUF_QUERY_LOADERS:Q}
INSTALL_TEMPLATES+=	../../graphics/gdk-pixbuf2/files/loaders.tmpl
DEINSTALL_TEMPLATES+=	../../graphics/gdk-pixbuf2/files/loaders.tmpl
.endif

#PRINT_PLIST_AWK+=	/^lib\/gdk-pixbuf-2.0/2.10.0/loaders.cache { next; }

.if !defined(_BUILDING_GTK2)
.  include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.endif

.endif			# GTK2_LOADERS_MK
