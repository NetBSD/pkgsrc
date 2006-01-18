# $NetBSD: plugins.mk,v 1.1 2006/01/18 12:44:04 jmmv Exp $
#
# This Makefile fragment is intended to be included by packages that install
# GStreamer modules.  It takes care of rebuilding the corresponding databases
# at (de)installation time.
#

.if !defined(GSTREAMER0.8_PLUGINS_MK)
GSTREAMER0.8_PLUGINS_MK=	# defined

GST0.8_DBDIR=		${BUILDLINK_PREFIX.gstreamer0.8}/libdata/gstreamer-0.8
GST0.8_COMPPREP=	${BUILDLINK_PREFIX.gstreamer0.8}/bin/gst-compprep-0.8
GST0.8_REGISTER=	${BUILDLINK_PREFIX.gstreamer0.8}/bin/gst-register-0.8

FILES_SUBST+=		GST0.8_DBDIR=${GST0.8_DBDIR:Q}
FILES_SUBST+=		GST0.8_COMPPREP=${GST0.8_COMPPREP:Q}
FILES_SUBST+=		GST0.8_REGISTER=${GST0.8_REGISTER:Q}
INSTALL_EXTRA_TMPL+=	../../multimedia/gstreamer0.8/files/plugins.tmpl
DEINSTALL_EXTRA_TMPL+=	../../multimedia/gstreamer0.8/files/plugins.tmpl

PRINT_PLIST_AWK+=	/^libdata\/gstreamer-0.8/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm libdata\/gstreamer-0.8/ { next; }

.if defined(_GSTREAMER0.8_NO_DEPEND)
BUILDLINK_PREFIX.gstreamer0.8=	${LOCALBASE}
.else
BUILDLINK_DEPENDS.gstreamer0.8+=	gstreamer0.8>=0.8.1
.  include "../../multimedia/gstreamer0.8/buildlink3.mk"
.endif

.endif			# GSTREAMER0.8_PLUGINS_MK
