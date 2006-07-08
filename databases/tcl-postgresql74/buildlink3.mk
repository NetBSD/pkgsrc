# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 22:39:05 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
TCL_POSTGRESQL74_BUILDLINK3_MK:=	${TCL_POSTGRESQL74_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl-postgresql74
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl-postgresql74}
BUILDLINK_PACKAGES+=	tcl-postgresql74
BUILDLINK_ORDER+=	tcl-postgresql74

.if !empty(TCL_POSTGRESQL74_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.tcl-postgresql74+=	tcl-postgresql74>=7.3.6
BUILDLINK_ABI_DEPENDS.tcl-postgresql74+=	tcl-postgresql74>=7.4.8nb1
BUILDLINK_PKGSRCDIR.tcl-postgresql74?=	../../databases/tcl-postgresql74
.endif	# TCL_POSTGRESQL74_BUILDLINK3_MK

.include "../../lang/tcl/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
