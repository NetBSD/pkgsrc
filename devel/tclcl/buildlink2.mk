# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/08/27 08:05:07 seb Exp $

.if !defined(TCLCL_BUILDLINK2_MK)
TCLCL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		tclcl
BUILDLINK_DEPENDS.tclcl?=	tclcl>=1.0rc12
BUILDLINK_PKGSRCDIR.tclcl?=      ../../devel/tclcl

EVAL_PREFIX+=	BUILDLINK_PREFIX.tclcl=tclcl
BUILDLINK_PREFIX.tclcl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tclcl+=	include/idlecallback.h
BUILDLINK_FILES.tclcl+=	include/iohandler.h
BUILDLINK_FILES.tclcl+=	include/rate-variable.h
BUILDLINK_FILES.tclcl+=	include/tclcl-config.h
BUILDLINK_FILES.tclcl+=	include/tclcl-internal.h
BUILDLINK_FILES.tclcl+=	include/tclcl-mappings.h
BUILDLINK_FILES.tclcl+=	include/tclcl.h
BUILDLINK_FILES.tclcl+=	include/timer.h
BUILDLINK_FILES.tclcl+=	include/tracedvar.h
BUILDLINK_FILES.tclcl+=	lib/libtclcl.*

.include  "../../lang/otcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"

BUILDLINK_TARGETS+=		tclcl-buildlink

tclcl-buildlink: _BUILDLINK_USE

.endif	# TCLCL_BUILDLINK2_MK
