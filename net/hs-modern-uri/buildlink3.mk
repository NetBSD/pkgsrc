# $NetBSD: buildlink3.mk,v 1.3 2025/03/05 03:39:46 pho Exp $

BUILDLINK_TREE+=	hs-modern-uri

.if !defined(HS_MODERN_URI_BUILDLINK3_MK)
HS_MODERN_URI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-modern-uri+=	hs-modern-uri>=0.3.6
BUILDLINK_ABI_DEPENDS.hs-modern-uri+=	hs-modern-uri>=0.3.6.1nb2
BUILDLINK_PKGSRCDIR.hs-modern-uri?=	../../net/hs-modern-uri

.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../devel/hs-reflection/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_MODERN_URI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-modern-uri
