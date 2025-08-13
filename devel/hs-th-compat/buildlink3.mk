# $NetBSD: buildlink3.mk,v 1.16 2025/08/13 11:07:01 pho Exp $

BUILDLINK_TREE+=	hs-th-compat

.if !defined(HS_TH_COMPAT_BUILDLINK3_MK)
HS_TH_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-th-compat+=	hs-th-compat>=0.1.6
BUILDLINK_ABI_DEPENDS.hs-th-compat+=	hs-th-compat>=0.1.6nb3
BUILDLINK_PKGSRCDIR.hs-th-compat?=	../../devel/hs-th-compat
.endif	# HS_TH_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-th-compat
