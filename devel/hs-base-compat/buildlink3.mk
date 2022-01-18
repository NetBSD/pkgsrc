# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:04 pho Exp $

BUILDLINK_TREE+=	hs-base-compat

.if !defined(HS_BASE_COMPAT_BUILDLINK3_MK)
HS_BASE_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-base-compat+=	hs-base-compat>=0.11.2
BUILDLINK_ABI_DEPENDS.hs-base-compat+=	hs-base-compat>=0.11.2nb2
BUILDLINK_PKGSRCDIR.hs-base-compat?=	../../devel/hs-base-compat
.endif	# HS_BASE_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-base-compat
