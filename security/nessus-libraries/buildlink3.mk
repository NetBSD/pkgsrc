# $NetBSD: buildlink3.mk,v 1.4 2004/10/03 00:18:10 tv Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
NESSUS_LIBRARIES_BUILDLINK3_MK:=	${NESSUS_LIBRARIES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	nessus-libraries
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnessus-libraries}
BUILDLINK_PACKAGES+=	nessus-libraries

.if !empty(NESSUS_LIBRARIES_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.nessus-libraries+=	nessus-libraries>=2.0.12
BUILDLINK_RECOMMENDED.nessus-libraries+=	nessus-libraries>=2.0.12nb1
BUILDLINK_PKGSRCDIR.nessus-libraries?=	../../security/nessus-libraries
.endif	# NESSUS_LIBRARIES_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
