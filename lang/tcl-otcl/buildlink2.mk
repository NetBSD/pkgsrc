# $NetBSD: buildlink2.mk,v 1.2 2002/09/02 23:12:23 seb Exp $

.if !defined(TCL_OTCL_BUILDLINK2_MK)
TCL_OTCL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			tcl-otcl
BUILDLINK_DEPENDS.tcl-otcl?=		tcl-otcl>=1.0rc8nb1
BUILDLINK_PKGSRCDIR.tcl-otcl?=		../../lang/tcl-otcl

EVAL_PREFIX+=				BUILDLINK_PREFIX.tcl-otcl=tcl-otcl
BUILDLINK_PREFIX.tcl-otcl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tcl-otcl+=		include/otcl.h
BUILDLINK_FILES.tcl-otcl+=		lib/libotcl.*

.include "../../x11/tk/buildlink2.mk"

BUILDLINK_TARGETS+=	tcl-otcl-buildlink

tcl-otcl-buildlink: _BUILDLINK_USE

.endif	# TCL_OTCL_BUILDLINK2_MK
