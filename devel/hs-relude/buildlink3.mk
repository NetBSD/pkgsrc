# $NetBSD: buildlink3.mk,v 1.2 2024/05/09 01:32:09 pho Exp $

BUILDLINK_TREE+=	hs-relude

.if !defined(HS_RELUDE_BUILDLINK3_MK)
HS_RELUDE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-relude+=	hs-relude>=1.2.1
BUILDLINK_ABI_DEPENDS.hs-relude+=	hs-relude>=1.2.1.0nb1
BUILDLINK_PKGSRCDIR.hs-relude?=		../../devel/hs-relude

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_RELUDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-relude
