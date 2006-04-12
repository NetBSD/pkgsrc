# $NetBSD: buildlink3.mk,v 1.6 2006/04/12 10:27:22 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TCL_ITCL_BUILDLINK3_MK:=	${TCL_ITCL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl-itcl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl-itcl}
BUILDLINK_PACKAGES+=	tcl-itcl

.if !empty(TCL_ITCL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.tcl-itcl+=	tcl-itcl>=3.2.1
BUILDLINK_ABI_DEPENDS.tcl-itcl?=	tcl-itcl>=3.2.1nb1
BUILDLINK_PKGSRCDIR.tcl-itcl?=	../../lang/tcl-itcl
.endif	# TCL_ITCL_BUILDLINK3_MK

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
