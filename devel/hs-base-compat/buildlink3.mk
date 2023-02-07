# $NetBSD: buildlink3.mk,v 1.9 2023/02/07 01:40:28 pho Exp $

BUILDLINK_TREE+=	hs-base-compat

.if !defined(HS_BASE_COMPAT_BUILDLINK3_MK)
HS_BASE_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-base-compat+=	hs-base-compat>=0.12.2
BUILDLINK_ABI_DEPENDS.hs-base-compat+=	hs-base-compat>=0.12.2nb1
BUILDLINK_PKGSRCDIR.hs-base-compat?=	../../devel/hs-base-compat
.endif	# HS_BASE_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-base-compat
