# $NetBSD: buildlink3.mk,v 1.14 2026/11/13 14:39:26 pho Exp $

BUILDLINK_TREE+=	hs-versions

.if !defined(HS_VERSIONS_BUILDLINK3_MK)
HS_VERSIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-versions+=	hs-versions>=6.0.7
BUILDLINK_ABI_DEPENDS.hs-versions+=	hs-versions>=6.0.7nb4
BUILDLINK_PKGSRCDIR.hs-versions?=	../../devel/hs-versions

.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.endif	# HS_VERSIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-versions
