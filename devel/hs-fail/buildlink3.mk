# $NetBSD: buildlink3.mk,v 1.5 2022/02/26 03:57:53 pho Exp $

BUILDLINK_TREE+=	hs-fail

.if !defined(HS_FAIL_BUILDLINK3_MK)
HS_FAIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fail+=	hs-fail>=4.9.0
BUILDLINK_ABI_DEPENDS.hs-fail+=	hs-fail>=4.9.0.0nb4
BUILDLINK_PKGSRCDIR.hs-fail?=	../../devel/hs-fail
.endif	# HS_FAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fail
