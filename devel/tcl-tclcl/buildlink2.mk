# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/08/28 10:00:11 seb Exp $

.if !defined(TCL_TCLCL_BUILDLINK2_MK)
TCL_TCLCL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			tcl-tclcl
BUILDLINK_DEPENDS.tcl-tclcl?=		tcl-tclcl>=1.0rc12
BUILDLINK_PKGSRCDIR.tcl-tclcl?=	      ../../devel/tcl-tclcl

EVAL_PREFIX+=	BUILDLINK_PREFIX.tcl-tclcl=tcl-tclcl
BUILDLINK_PREFIX.tcl-tclcl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tcl-tclcl+=		include/idlecallback.h
BUILDLINK_FILES.tcl-tclcl+=		include/iohandler.h
BUILDLINK_FILES.tcl-tclcl+=		include/rate-variable.h
BUILDLINK_FILES.tcl-tclcl+=		include/tclcl-config.h
BUILDLINK_FILES.tcl-tclcl+=		include/tclcl-internal.h
BUILDLINK_FILES.tcl-tclcl+=		include/tclcl-mappings.h
BUILDLINK_FILES.tcl-tclcl+=		include/tclcl.h
BUILDLINK_FILES.tcl-tclcl+=		include/timer.h
BUILDLINK_FILES.tcl-tclcl+=		include/tracedvar.h
BUILDLINK_FILES.tcl-tclcl+=		lib/libtclcl.*

.include  "../../lang/tcl-otcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"

BUILDLINK_TARGETS+=		tcl-tclcl-buildlink

tcl-tclcl-buildlink: _BUILDLINK_USE

.endif	# TCL_TCLCL_BUILDLINK2_MK
