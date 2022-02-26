# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:06 pho Exp $

BUILDLINK_TREE+=	hs-retry

.if !defined(HS_RETRY_BUILDLINK3_MK)
HS_RETRY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-retry+=	hs-retry>=0.9.1
BUILDLINK_ABI_DEPENDS.hs-retry+=	hs-retry>=0.9.1.0nb1
BUILDLINK_PKGSRCDIR.hs-retry?=		../../devel/hs-retry

.include "../../devel/hs-random/buildlink3.mk"
.endif	# HS_RETRY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-retry
