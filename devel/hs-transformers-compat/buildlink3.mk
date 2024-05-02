# $NetBSD: buildlink3.mk,v 1.15 2024/05/02 10:00:01 pho Exp $

BUILDLINK_TREE+=	hs-transformers-compat

.if !defined(HS_TRANSFORMERS_COMPAT_BUILDLINK3_MK)
HS_TRANSFORMERS_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-transformers-compat+=	hs-transformers-compat>=0.7.2
BUILDLINK_ABI_DEPENDS.hs-transformers-compat+=	hs-transformers-compat>=0.7.2nb4
BUILDLINK_PKGSRCDIR.hs-transformers-compat?=	../../devel/hs-transformers-compat

.endif	# HS_TRANSFORMERS_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-transformers-compat
