# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:32:25 riastradh Exp $

BUILDLINK_TREE+=	hs-Only

.if !defined(HS_ONLY_BUILDLINK3_MK)
HS_ONLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Only+=	hs-Only>=0.1
BUILDLINK_ABI_DEPENDS.hs-Only+=	hs-Only>=0.1
BUILDLINK_PKGSRCDIR.hs-Only?=	../../devel/hs-Only
.endif	# HS_ONLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Only
