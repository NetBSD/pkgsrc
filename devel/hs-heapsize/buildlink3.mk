# $NetBSD: buildlink3.mk,v 1.6 2023/11/02 06:36:34 pho Exp $

BUILDLINK_TREE+=	hs-heapsize

.if !defined(HS_HEAPSIZE_BUILDLINK3_MK)
HS_HEAPSIZE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-heapsize+=	hs-heapsize>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-heapsize+=	hs-heapsize>=0.3.0.1nb5
BUILDLINK_PKGSRCDIR.hs-heapsize?=	../../devel/hs-heapsize

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hashtables/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_HEAPSIZE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-heapsize
