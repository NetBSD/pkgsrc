# $NetBSD: buildlink3.mk,v 1.1 2004/05/03 05:52:55 snj Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
NESSUS_CORE_BUILDLINK3_MK:=	${NESSUS_CORE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	nessus-core
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnessus-core}
BUILDLINK_PACKAGES+=	nessus-core

.if !empty(NESSUS_CORE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.nessus-core+=	nessus-core>=2.0.9
BUILDLINK_RECOMMENDED.nessus-core?=	nessus-core>=2.0.9nb1
BUILDLINK_PKGSRCDIR.nessus-core?=	../../security/nessus-core
.endif	# NESSUS_CORE_BUILDLINK3_MK

.include "../../security/libnasl/buildlink3.mk"
.include "../../security/nessus-libraries/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
