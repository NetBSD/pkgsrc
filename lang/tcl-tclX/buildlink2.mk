# $NetBSD: buildlink2.mk,v 1.1 2004/03/20 19:28:52 minskim Exp $

.if !defined(TCL_TCLX_BUILDLINK2_MK)
TCL_TCLX_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		tcl-tclX
BUILDLINK_DEPENDS.tcl-tclX?=	tcl-tclX>=8.2.0nb1
BUILDLINK_PKGSRCDIR.tcl-tclX?=	../../lang/tcl-tclX

EVAL_PREFIX+=	BUILDLINK_PREFIX.tcl-tclX=tcl-tclX
BUILDLINK_PREFIX.tcl-tclX_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tcl-tclX+=	include/*.h
BUILDLINK_FILES.tcl-tclX+=	lib/libtclx82.*

.include "../../lang/tcl/buildlink2.mk"

BUILDLINK_TARGETS+=	tcl-tclX-buildlink

tcl-tclX-buildlink: _BUILDLINK_USE

.endif	# TCL_TCLX_BUILDLINK2_MK
