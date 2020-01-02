# $NetBSD: buildlink3.mk,v 1.1 2020/01/02 17:37:50 pho Exp $

BUILDLINK_TREE+=	hs-async

.if !defined(HS_ASYNC_BUILDLINK3_MK)
HS_ASYNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-async+=	hs-async>=2.2.2
BUILDLINK_ABI_DEPENDS.hs-async+=	hs-async>=2.2.2
BUILDLINK_PKGSRCDIR.hs-async?=	../../devel/hs-async

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-stm/buildlink3.mk"
.endif	# HS_ASYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-async
