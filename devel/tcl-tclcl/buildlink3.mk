# $NetBSD: buildlink3.mk,v 1.2 2004/03/18 09:12:11 jlam Exp $

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
.endif	# TCL_TCLCL_BUILDLINK3_MK

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-otcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
