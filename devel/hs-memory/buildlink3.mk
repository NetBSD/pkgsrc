# $NetBSD: buildlink3.mk,v 1.6 2022/02/26 03:58:01 pho Exp $

BUILDLINK_TREE+=	hs-memory

.if !defined(HS_MEMORY_BUILDLINK3_MK)
HS_MEMORY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-memory+=	hs-memory>=0.16.0
BUILDLINK_ABI_DEPENDS.hs-memory+=	hs-memory>=0.16.0nb2
BUILDLINK_PKGSRCDIR.hs-memory?=		../../devel/hs-memory

.include "../../devel/hs-basement/buildlink3.mk"
.endif	# HS_MEMORY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-memory
