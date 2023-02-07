# $NetBSD: buildlink3.mk,v 1.9 2023/02/07 01:40:43 pho Exp $

BUILDLINK_TREE+=	hs-memory

.if !defined(HS_MEMORY_BUILDLINK3_MK)
HS_MEMORY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-memory+=	hs-memory>=0.18.0
BUILDLINK_ABI_DEPENDS.hs-memory+=	hs-memory>=0.18.0nb2
BUILDLINK_PKGSRCDIR.hs-memory?=		../../devel/hs-memory

.include "../../devel/hs-basement/buildlink3.mk"
.endif	# HS_MEMORY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-memory
