# $NetBSD: buildlink3.mk,v 1.4 2006/04/06 06:22:49 reed Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CHASEN_BASE_BUILDLINK3_MK:=	${CHASEN_BASE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	chasen-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nchasen-base}
BUILDLINK_PACKAGES+=	chasen-base

.if !empty(CHASEN_BASE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.chasen-base+=	chasen-base>=2.3.3
BUILDLINK_ABI_DEPENDS.chasen-base+=	chasen-base>=2.3.3nb1
BUILDLINK_PKGSRCDIR.chasen-base?=	../../textproc/chasen-base
.endif	# CHASEN_BASE_BUILDLINK3_MK

.include "../../devel/darts/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
