# $NetBSD: buildlink3.mk,v 1.3 2006/02/05 23:09:52 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TCL_OTCL_BUILDLINK3_MK:=	${TCL_OTCL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl-otcl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl-otcl}
BUILDLINK_PACKAGES+=	tcl-otcl

.if !empty(TCL_OTCL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.tcl-otcl+=	tcl-otcl>=1.8
BUILDLINK_RECOMMENDED.tcl-otcl?=	tcl-otcl>=1.11nb1
BUILDLINK_PKGSRCDIR.tcl-otcl?=	../../lang/tcl-otcl
.endif	# TCL_OTCL_BUILDLINK3_MK

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
