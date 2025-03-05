# $NetBSD: buildlink3.mk,v 1.8 2025/03/05 03:39:22 pho Exp $

BUILDLINK_TREE+=	hs-mtl-compat

.if !defined(HS_MTL_COMPAT_BUILDLINK3_MK)
HS_MTL_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mtl-compat+=	hs-mtl-compat>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-mtl-compat+=	hs-mtl-compat>=0.2.2nb7
BUILDLINK_PKGSRCDIR.hs-mtl-compat?=	../../devel/hs-mtl-compat
.endif	# HS_MTL_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mtl-compat
