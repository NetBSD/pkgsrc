# $NetBSD: buildlink3.mk,v 1.10 2025/02/02 13:05:05 pho Exp $

BUILDLINK_TREE+=	hs-fail

.if !defined(HS_FAIL_BUILDLINK3_MK)
HS_FAIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fail+=	hs-fail>=4.9.0
BUILDLINK_ABI_DEPENDS.hs-fail+=	hs-fail>=4.9.0.0nb9
BUILDLINK_PKGSRCDIR.hs-fail?=	../../devel/hs-fail
.endif	# HS_FAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fail
