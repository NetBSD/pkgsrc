# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:10 pho Exp $

BUILDLINK_TREE+=	hs-memory

.if !defined(HS_MEMORY_BUILDLINK3_MK)
HS_MEMORY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-memory+=	hs-memory>=0.15.0
BUILDLINK_ABI_DEPENDS.hs-memory+=	hs-memory>=0.15.0nb2
BUILDLINK_PKGSRCDIR.hs-memory?=		../../devel/hs-memory

.include "../../devel/hs-basement/buildlink3.mk"
.endif	# HS_MEMORY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-memory
