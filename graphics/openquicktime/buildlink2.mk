# $NetBSD: buildlink2.mk,v 1.1 2003/04/23 10:26:42 rh Exp $
#
# This Makefile fragment is included by packages that use openquicktime.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(OPENQUICKTIME_BUILDLINK2_MK)
OPENQUICKTIME_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			openquicktime
BUILDLINK_DEPENDS.openquicktime?=		openquicktime>=1.0
BUILDLINK_PKGSRCDIR.openquicktime?=		../../graphics/openquicktime

EVAL_PREFIX+=	BUILDLINK_PREFIX.openquicktime=openquicktime
BUILDLINK_PREFIX.openquicktime_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.openquicktime+=	include/openquicktime/*.h
BUILDLINK_FILES.openquicktime+=	lib/libopenquicktime.*
BUILDLINK_FILES.openquicktime+=	lib/quicktime_codec_.mp3.*
BUILDLINK_FILES.openquicktime+=	lib/quicktime_codec_jpeg.*
BUILDLINK_FILES.openquicktime+=	lib/quicktime_codec_ms.*

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"

BUILDLINK_TARGETS+=	openquicktime-buildlink

openquicktime-buildlink: _BUILDLINK_USE

.endif	# OPENQUICKTIME_BUILDLINK2_MK
