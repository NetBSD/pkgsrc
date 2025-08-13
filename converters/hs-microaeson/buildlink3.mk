# $NetBSD: buildlink3.mk,v 1.6 2025/08/13 11:06:25 pho Exp $

BUILDLINK_TREE+=	hs-microaeson

.if !defined(HS_MICROAESON_BUILDLINK3_MK)
HS_MICROAESON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-microaeson+=	hs-microaeson>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-microaeson+=	hs-microaeson>=0.1.0.2nb3
BUILDLINK_PKGSRCDIR.hs-microaeson?=	../../converters/hs-microaeson

.include "../../devel/hs-fail/buildlink3.mk"
.endif	# HS_MICROAESON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-microaeson
