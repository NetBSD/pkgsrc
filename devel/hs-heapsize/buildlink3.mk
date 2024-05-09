# $NetBSD: buildlink3.mk,v 1.7 2024/05/09 01:31:58 pho Exp $

BUILDLINK_TREE+=	hs-heapsize

.if !defined(HS_HEAPSIZE_BUILDLINK3_MK)
HS_HEAPSIZE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-heapsize+=	hs-heapsize>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-heapsize+=	hs-heapsize>=0.3.0.1nb6
BUILDLINK_PKGSRCDIR.hs-heapsize?=	../../devel/hs-heapsize

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hashtables/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HEAPSIZE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-heapsize
