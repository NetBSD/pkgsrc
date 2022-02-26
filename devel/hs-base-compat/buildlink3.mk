# $NetBSD: buildlink3.mk,v 1.7 2022/02/26 03:57:49 pho Exp $

BUILDLINK_TREE+=	hs-base-compat

.if !defined(HS_BASE_COMPAT_BUILDLINK3_MK)
HS_BASE_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-base-compat+=	hs-base-compat>=0.12.1
BUILDLINK_ABI_DEPENDS.hs-base-compat+=	hs-base-compat>=0.12.1nb2
BUILDLINK_PKGSRCDIR.hs-base-compat?=	../../devel/hs-base-compat
.endif	# HS_BASE_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-base-compat
