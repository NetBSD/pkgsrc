# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:15:03 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TCL_ITCL_BUILDLINK3_MK:=	${TCL_ITCL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl-itcl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl-itcl}
BUILDLINK_PACKAGES+=	tcl-itcl

.if !empty(TCL_ITCL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.tcl-itcl+=	tcl-itcl>=3.2
BUILDLINK_RECOMMENDED.tcl-itcl+=	tcl-itcl>=3.2nb2
BUILDLINK_PKGSRCDIR.tcl-itcl?=	../../lang/tcl-itcl
.endif	# TCL_ITCL_BUILDLINK3_MK

.include "../../lang/tcl83/buildlink3.mk"
.include "../../x11/tk83/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
