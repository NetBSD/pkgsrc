# $NetBSD: buildlink3.mk,v 1.9 2024/05/09 01:31:54 pho Exp $

BUILDLINK_TREE+=	hs-fail

.if !defined(HS_FAIL_BUILDLINK3_MK)
HS_FAIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fail+=	hs-fail>=4.9.0
BUILDLINK_ABI_DEPENDS.hs-fail+=	hs-fail>=4.9.0.0nb8
BUILDLINK_PKGSRCDIR.hs-fail?=	../../devel/hs-fail
.endif	# HS_FAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fail
