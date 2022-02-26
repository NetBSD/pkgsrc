# $NetBSD: buildlink3.mk,v 1.8 2022/02/26 03:57:48 pho Exp $

BUILDLINK_TREE+=	hs-async

.if !defined(HS_ASYNC_BUILDLINK3_MK)
HS_ASYNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-async+=	hs-async>=2.2.4
BUILDLINK_ABI_DEPENDS.hs-async+=	hs-async>=2.2.4nb2
BUILDLINK_PKGSRCDIR.hs-async?=		../../devel/hs-async

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_ASYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-async
