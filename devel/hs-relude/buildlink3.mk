# $NetBSD: buildlink3.mk,v 1.3 2025/01/31 10:51:27 pho Exp $

BUILDLINK_TREE+=	hs-relude

.if !defined(HS_RELUDE_BUILDLINK3_MK)
HS_RELUDE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-relude+=	hs-relude>=1.2.2
BUILDLINK_ABI_DEPENDS.hs-relude+=	hs-relude>=1.2.2.0
BUILDLINK_PKGSRCDIR.hs-relude?=		../../devel/hs-relude

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_RELUDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-relude
