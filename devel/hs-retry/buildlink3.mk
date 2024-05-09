# $NetBSD: buildlink3.mk,v 1.8 2024/05/09 01:32:09 pho Exp $

BUILDLINK_TREE+=	hs-retry

.if !defined(HS_RETRY_BUILDLINK3_MK)
HS_RETRY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-retry+=	hs-retry>=0.9.3
BUILDLINK_ABI_DEPENDS.hs-retry+=	hs-retry>=0.9.3.1nb2
BUILDLINK_PKGSRCDIR.hs-retry?=		../../devel/hs-retry

.include "../../devel/hs-mtl-compat/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.endif	# HS_RETRY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-retry
