# $NetBSD: buildlink3.mk,v 1.13 2024/05/09 01:31:39 pho Exp $

BUILDLINK_TREE+=	hs-aeson-pretty

.if !defined(HS_AESON_PRETTY_BUILDLINK3_MK)
HS_AESON_PRETTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-aeson-pretty+=	hs-aeson-pretty>=0.8.10
BUILDLINK_ABI_DEPENDS.hs-aeson-pretty+=	hs-aeson-pretty>=0.8.10nb2
BUILDLINK_PKGSRCDIR.hs-aeson-pretty?=	../../converters/hs-aeson-pretty

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_AESON_PRETTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-aeson-pretty
