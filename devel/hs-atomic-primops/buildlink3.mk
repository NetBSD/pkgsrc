# $NetBSD: buildlink3.mk,v 1.3 2024/04/29 08:56:01 pho Exp $

BUILDLINK_TREE+=	hs-atomic-primops

.if !defined(HS_ATOMIC_PRIMOPS_BUILDLINK3_MK)
HS_ATOMIC_PRIMOPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-atomic-primops+=	hs-atomic-primops>=0.8.7
BUILDLINK_ABI_DEPENDS.hs-atomic-primops+=	hs-atomic-primops>=0.8.7
BUILDLINK_PKGSRCDIR.hs-atomic-primops?=		../../devel/hs-atomic-primops

.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_ATOMIC_PRIMOPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-atomic-primops
