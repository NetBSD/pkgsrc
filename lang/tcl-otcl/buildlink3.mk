# $NetBSD: buildlink3.mk,v 1.2 2004/03/18 09:12:13 jlam Exp $

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
.endif	# TCL_OTCL_BUILDLINK3_MK

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
