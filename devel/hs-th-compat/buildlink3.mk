# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:13 pho Exp $

BUILDLINK_TREE+=	hs-th-compat

.if !defined(HS_TH_COMPAT_BUILDLINK3_MK)
HS_TH_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-th-compat+=	hs-th-compat>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-th-compat+=	hs-th-compat>=0.1.2nb2
BUILDLINK_PKGSRCDIR.hs-th-compat?=	../../devel/hs-th-compat
.endif	# HS_TH_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-th-compat
