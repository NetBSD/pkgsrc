# $NetBSD: plugins.mk,v 1.1 2004/04/06 09:30:01 jmmv Exp $
#
# This Makefile fragment is intended to be included by packages that install
# GStreamer modules.  It takes care of rebuilding the corresponding databases
# at (de)installation time.
#

.if !defined(GSTREAMER_PLUGINS_MK)
GSTREAMER_PLUGINS_MK=	# defined

GST_DBDIR=		${BUILDLINK_PREFIX.gstreamer}/libdata/gstreamer-0.8
GST_COMPPREP=		${BUILDLINK_PREFIX.gstreamer}/bin/gst-compprep
GST_REGISTER=		${BUILDLINK_PREFIX.gstreamer}/bin/gst-register

FILES_SUBST+=		GST_DBDIR="${GST_DBDIR}"
FILES_SUBST+=		GST_COMPPREP="${GST_COMPPREP}"
FILES_SUBST+=		GST_REGISTER="${GST_REGISTER}"
INSTALL_EXTRA_TMPL+=	../../multimedia/gstreamer/files/plugins.tmpl
DEINSTALL_EXTRA_TMPL+=	../../multimedia/gstreamer/files/plugins.tmpl
USE_PKGINSTALL=		YES

.if defined(_GSTREAMER_NO_DEPEND)
BUILDLINK_PREFIX.gstreamer=	${LOCALBASE}
.else
USE_BUILDLINK3=		YES
.  include "../../multimedia/gstreamer/buildlink3.mk"
.endif

.endif			# GSTREAMER_PLUGINS_MK
