# $NetBSD: buildlink2.mk,v 1.7 2003/12/13 00:45:24 wiz Exp $
#
# This Makefile fragment is included by packages that use gstreamer.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(GSTREAMER_BUILDLINK2_MK)
GSTREAMER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gstreamer
BUILDLINK_DEPENDS.gstreamer?=		gstreamer>=0.6.1nb6
BUILDLINK_PKGSRCDIR.gstreamer?=		../../misc/gstreamer

EVAL_PREFIX+=	BUILDLINK_PREFIX.gstreamer=gstreamer
BUILDLINK_PREFIX.gstreamer_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/*.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/bytestream/*.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/control/*.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/getbits/*.h
BUILDLINK_FILES.gstreamer+=	include/gstreamer-0.6/gst/putbits/*.h
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstautoplugcache.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstautoplugger.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstbasicgthreadscheduler.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstbasicomegascheduler.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstbasicwingoscheduler.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstbytestream.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstelements.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstgetbits.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstindexers.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstoptgthreadscheduler.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstoptomegascheduler.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstoptscheduler.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstoptwingoscheduler.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstputbits.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgstspider.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgststaticautoplug.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgststaticautoplugrender.*
BUILDLINK_FILES.gstreamer+=	lib/gstreamer-0.6/libgsttypes.*
BUILDLINK_FILES.gstreamer+=	lib/libgstcontrol-0.6.*
BUILDLINK_FILES.gstreamer+=	lib/libgstreamer-0.6.*
BUILDLINK_FILES.gstreamer+=	lib/pkgconfig/gstreamer-0.6.pc
BUILDLINK_FILES.gstreamer+=	lib/pkgconfig/gstreamer-control-0.6.pc

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"

BUILDLINK_TARGETS+=	gstreamer-buildlink

gstreamer-buildlink: _BUILDLINK_USE

.endif	# GSTREAMER_BUILDLINK2_MK
