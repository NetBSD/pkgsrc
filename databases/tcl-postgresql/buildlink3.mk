# $NetBSD: buildlink3.mk,v 1.2 2004/03/18 09:12:09 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TCL_POSTGRESQL_BUILDLINK3_MK:=	${TCL_POSTGRESQL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl-postgresql
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl-postgresql}
BUILDLINK_PACKAGES+=	tcl-postgresql

.if !empty(TCL_POSTGRESQL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.tcl-postgresql+=	tcl-postgresql>=7.3.1
BUILDLINK_PKGSRCDIR.tcl-postgresql?=	../../databases/tcl-postgresql
.endif	# TCL_POSTGRESQL_BUILDLINK3_MK

.include "../../lang/tcl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
