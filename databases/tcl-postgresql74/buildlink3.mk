# $NetBSD: buildlink3.mk,v 1.3 2006/04/06 06:21:43 reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TCL_POSTGRESQL73_BUILDLINK3_MK:=	${TCL_POSTGRESQL73_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl-postgresql73
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl-postgresql73}
BUILDLINK_PACKAGES+=	tcl-postgresql73

.if !empty(TCL_POSTGRESQL73_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.tcl-postgresql73+=	tcl-postgresql73>=7.3.6
BUILDLINK_ABI_DEPENDS.tcl-postgresql73?=	tcl-postgresql74>=7.4.8nb1
BUILDLINK_PKGSRCDIR.tcl-postgresql73?=	../../databases/tcl-postgresql73
.endif	# TCL_POSTGRESQL73_BUILDLINK3_MK

.include "../../lang/tcl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
