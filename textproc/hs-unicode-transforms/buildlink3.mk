# $NetBSD: buildlink3.mk,v 1.3 2021/05/03 19:01:18 pho Exp $

BUILDLINK_TREE+=	hs-unicode-transforms

.if !defined(HS_UNICODE_TRANSFORMS_BUILDLINK3_MK)
HS_UNICODE_TRANSFORMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unicode-transforms+=	hs-unicode-transforms>=0.3.7
BUILDLINK_ABI_DEPENDS.hs-unicode-transforms+=	hs-unicode-transforms>=0.3.7.1nb1
BUILDLINK_PKGSRCDIR.hs-unicode-transforms?=	../../textproc/hs-unicode-transforms
.endif	# HS_UNICODE_TRANSFORMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unicode-transforms
