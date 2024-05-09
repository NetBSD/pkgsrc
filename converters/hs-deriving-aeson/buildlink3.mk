# $NetBSD: buildlink3.mk,v 1.5 2024/05/09 01:31:40 pho Exp $

BUILDLINK_TREE+=	hs-deriving-aeson

.if !defined(HS_DERIVING_AESON_BUILDLINK3_MK)
HS_DERIVING_AESON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-deriving-aeson+=	hs-deriving-aeson>=0.2.9
BUILDLINK_ABI_DEPENDS.hs-deriving-aeson+=	hs-deriving-aeson>=0.2.9nb4
BUILDLINK_PKGSRCDIR.hs-deriving-aeson?=		../../converters/hs-deriving-aeson

.include "../../converters/hs-aeson/buildlink3.mk"
.endif	# HS_DERIVING_AESON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-deriving-aeson
