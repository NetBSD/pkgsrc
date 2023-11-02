# $NetBSD: buildlink3.mk,v 1.23 2023/11/02 06:37:14 pho Exp $

BUILDLINK_TREE+=	hs-scientific

.if !defined(HS_SCIENTIFIC_BUILDLINK3_MK)
HS_SCIENTIFIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-scientific+=	hs-scientific>=0.3.7
BUILDLINK_ABI_DEPENDS.hs-scientific+=	hs-scientific>=0.3.7.0nb5
BUILDLINK_PKGSRCDIR.hs-scientific?=	../../math/hs-scientific

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../math/hs-integer-logarithms/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_SCIENTIFIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-scientific
