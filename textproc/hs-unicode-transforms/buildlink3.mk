# $NetBSD: buildlink3.mk,v 1.1 2020/01/17 18:49:18 pho Exp $

BUILDLINK_TREE+=	hs-unicode-transforms

.if !defined(HS_UNICODE_TRANSFORMS_BUILDLINK3_MK)
HS_UNICODE_TRANSFORMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unicode-transforms+=	hs-unicode-transforms>=0.3.6
BUILDLINK_ABI_DEPENDS.hs-unicode-transforms+=	hs-unicode-transforms>=0.3.6
BUILDLINK_PKGSRCDIR.hs-unicode-transforms?=	../../textproc/hs-unicode-transforms

.include "../../devel/hs-bitarray/buildlink3.mk"
.endif	# HS_UNICODE_TRANSFORMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unicode-transforms
