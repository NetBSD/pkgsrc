# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/09/24 21:16:02 dmcmahill Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TCL_ITCL_CURRENT_BUILDLINK3_MK:=	${TCL_ITCL_CURRENT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl-itcl-current
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl-itcl-current}
BUILDLINK_PACKAGES+=	tcl-itcl-current

.if !empty(TCL_ITCL_CURRENT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.tcl-itcl-current+=	tcl-itcl-current>=20040920
BUILDLINK_PKGSRCDIR.tcl-itcl-current?=	../../lang/tcl-itcl-current
.endif	# TCL_ITCL_CURRENT_BUILDLINK3_MK

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
