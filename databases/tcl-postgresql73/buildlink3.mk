# $NetBSD: buildlink3.mk,v 1.3 2004/07/27 19:29:45 recht Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TCL_POSTGRESQL73_BUILDLINK3_MK:=	${TCL_POSTGRESQL73_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl-postgresql73
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl-postgresql73}
BUILDLINK_PACKAGES+=	tcl-postgresql73

.if !empty(TCL_POSTGRESQL73_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.tcl-postgresql73+=	tcl-postgresql73>=7.3.6
BUILDLINK_PKGSRCDIR.tcl-postgresql73?=	../../databases/tcl-postgresql73
.endif	# TCL_POSTGRESQL73_BUILDLINK3_MK

.include "../../lang/tcl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
