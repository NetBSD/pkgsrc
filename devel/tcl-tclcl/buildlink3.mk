# $NetBSD: buildlink3.mk,v 1.1 2004/03/08 23:49:41 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TCL_TCLCL_BUILDLINK3_MK:=	${TCL_TCLCL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl-tclcl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl-tclcl}
BUILDLINK_PACKAGES+=	tcl-tclcl

.if !empty(TCL_TCLCL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.tcl-tclcl+=	tcl-tclcl>=1.15
BUILDLINK_PKGSRCDIR.tcl-tclcl?=	../../devel/tcl-tclcl

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-otcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.endif	# TCL_TCLCL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
