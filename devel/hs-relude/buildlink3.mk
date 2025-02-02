# $NetBSD: buildlink3.mk,v 1.4 2025/02/02 13:05:20 pho Exp $

BUILDLINK_TREE+=	hs-relude

.if !defined(HS_RELUDE_BUILDLINK3_MK)
HS_RELUDE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-relude+=	hs-relude>=1.2.2
BUILDLINK_ABI_DEPENDS.hs-relude+=	hs-relude>=1.2.2.0nb1
BUILDLINK_PKGSRCDIR.hs-relude?=		../../devel/hs-relude

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_RELUDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-relude
