# $NetBSD: buildlink3.mk,v 1.9 2024/05/09 01:32:19 pho Exp $

BUILDLINK_TREE+=	hs-versions

.if !defined(HS_VERSIONS_BUILDLINK3_MK)
HS_VERSIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-versions+=	hs-versions>=6.0.6
BUILDLINK_ABI_DEPENDS.hs-versions+=	hs-versions>=6.0.6nb1
BUILDLINK_PKGSRCDIR.hs-versions?=	../../devel/hs-versions

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.endif	# HS_VERSIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-versions
