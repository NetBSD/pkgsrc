# $NetBSD: buildlink3.mk,v 1.2 2021/04/24 17:31:23 pho Exp $

BUILDLINK_TREE+=	hs-unicode-transforms

.if !defined(HS_UNICODE_TRANSFORMS_BUILDLINK3_MK)
HS_UNICODE_TRANSFORMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unicode-transforms+=	hs-unicode-transforms>=0.3.7
BUILDLINK_ABI_DEPENDS.hs-unicode-transforms+=	hs-unicode-transforms>=0.3.7.1
BUILDLINK_PKGSRCDIR.hs-unicode-transforms?=	../../textproc/hs-unicode-transforms
.endif	# HS_UNICODE_TRANSFORMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unicode-transforms
