# $NetBSD: buildlink3.mk,v 1.13 2025/01/30 04:36:49 pho Exp $

BUILDLINK_TREE+=	hs-th-compat

.if !defined(HS_TH_COMPAT_BUILDLINK3_MK)
HS_TH_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-th-compat+=	hs-th-compat>=0.1.6
BUILDLINK_ABI_DEPENDS.hs-th-compat+=	hs-th-compat>=0.1.6
BUILDLINK_PKGSRCDIR.hs-th-compat?=	../../devel/hs-th-compat
.endif	# HS_TH_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-th-compat
