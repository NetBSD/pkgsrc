# $NetBSD: buildlink3.mk,v 1.2 2024/05/09 01:31:41 pho Exp $

BUILDLINK_TREE+=	hs-microaeson

.if !defined(HS_MICROAESON_BUILDLINK3_MK)
HS_MICROAESON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-microaeson+=	hs-microaeson>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-microaeson+=	hs-microaeson>=0.1.0.1nb1
BUILDLINK_PKGSRCDIR.hs-microaeson?=	../../converters/hs-microaeson

.include "../../devel/hs-fail/buildlink3.mk"
.endif	# HS_MICROAESON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-microaeson
