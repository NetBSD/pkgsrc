# $NetBSD: buildlink3.mk,v 1.1 2022/02/24 01:01:42 pho Exp $

BUILDLINK_TREE+=	hs-retry

.if !defined(HS_RETRY_BUILDLINK3_MK)
HS_RETRY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-retry+=	hs-retry>=0.9.1
BUILDLINK_ABI_DEPENDS.hs-retry+=	hs-retry>=0.9.1.0
BUILDLINK_PKGSRCDIR.hs-retry?=		../../devel/hs-retry

.include "../../devel/hs-random/buildlink3.mk"
.endif	# HS_RETRY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-retry
