# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/02/16 05:58:49 salo Exp $
#
# This Makefile fragment is included by packages that use streamtuner.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(STREAMTUNER_BUILDLINK2_MK)
STREAMTUNER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			streamtuner
BUILDLINK_DEPENDS.streamtuner?=		streamtuner>=0.9.0
BUILDLINK_PKGSRCDIR.streamtuner?=		../../audio/streamtuner

EVAL_PREFIX+=	BUILDLINK_PREFIX.streamtuner=streamtuner
BUILDLINK_PREFIX.streamtuner_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.streamtuner+=	include/streamtuner/st_category.h
BUILDLINK_FILES.streamtuner+=	include/streamtuner/st_dialog.h
BUILDLINK_FILES.streamtuner+=	include/streamtuner/st_handler.h
BUILDLINK_FILES.streamtuner+=	include/streamtuner/st_handler_field.h
BUILDLINK_FILES.streamtuner+=	include/streamtuner/st_handlers.h
BUILDLINK_FILES.streamtuner+=	include/streamtuner/st_programs.h
BUILDLINK_FILES.streamtuner+=	include/streamtuner/st_re.h
BUILDLINK_FILES.streamtuner+=	include/streamtuner/st_state.h
BUILDLINK_FILES.streamtuner+=	include/streamtuner/st_stream.h
BUILDLINK_FILES.streamtuner+=	include/streamtuner/st_transfer.h
BUILDLINK_FILES.streamtuner+=	include/streamtuner/st_version.h
BUILDLINK_FILES.streamtuner+=	include/streamtuner/streamtuner.h
BUILDLINK_FILES.streamtuner+=	lib/pkgconfig/streamtuner.pc
BUILDLINK_FILES.streamtuner+=	lib/streamtuner/plugins/shoutcast.*

.include "../../www/curl/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	streamtuner-buildlink

streamtuner-buildlink: _BUILDLINK_USE

.endif	# STREAMTUNER_BUILDLINK2_MK
