# $NetBSD: buildlink3.mk,v 1.8 2025/03/05 03:38:57 pho Exp $

BUILDLINK_TREE+=	hs-deriving-aeson

.if !defined(HS_DERIVING_AESON_BUILDLINK3_MK)
HS_DERIVING_AESON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-deriving-aeson+=	hs-deriving-aeson>=0.2.10
BUILDLINK_ABI_DEPENDS.hs-deriving-aeson+=	hs-deriving-aeson>=0.2.10nb2
BUILDLINK_PKGSRCDIR.hs-deriving-aeson?=		../../converters/hs-deriving-aeson

.include "../../converters/hs-aeson/buildlink3.mk"
.endif	# HS_DERIVING_AESON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-deriving-aeson
