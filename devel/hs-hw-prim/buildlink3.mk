# $NetBSD: buildlink3.mk,v 1.1 2023/01/30 06:58:05 pho Exp $

BUILDLINK_TREE+=	hs-hw-prim

.if !defined(HS_HW_PRIM_BUILDLINK3_MK)
HS_HW_PRIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hw-prim+=	hs-hw-prim>=0.6.3
BUILDLINK_ABI_DEPENDS.hs-hw-prim+=	hs-hw-prim>=0.6.3.2
BUILDLINK_PKGSRCDIR.hs-hw-prim?=	../../devel/hs-hw-prim

.include "../../devel/hs-mmap/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_HW_PRIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hw-prim
