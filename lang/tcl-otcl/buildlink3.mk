# $NetBSD: buildlink3.mk,v 1.1 2004/03/08 23:47:44 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TCL_OTCL_BUILDLINK3_MK:=	${TCL_OTCL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl-otcl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl-otcl}
BUILDLINK_PACKAGES+=	tcl-otcl

.if !empty(TCL_OTCL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.tcl-otcl+=	tcl-otcl>=1.8
BUILDLINK_PKGSRCDIR.tcl-otcl?=	../../lang/tcl-otcl

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.endif	# TCL_OTCL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
