# $NetBSD: buildlink3.mk,v 1.12 2024/04/29 12:11:10 pho Exp $

BUILDLINK_TREE+=	hs-async

.if !defined(HS_ASYNC_BUILDLINK3_MK)
HS_ASYNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-async+=	hs-async>=2.2.5
BUILDLINK_ABI_DEPENDS.hs-async+=	hs-async>=2.2.5
BUILDLINK_PKGSRCDIR.hs-async?=		../../devel/hs-async

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_ASYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-async
