# $NetBSD: buildlink3.mk,v 1.1 2022/02/24 01:23:25 pho Exp $

BUILDLINK_TREE+=	hs-versions

.if !defined(HS_VERSIONS_BUILDLINK3_MK)
HS_VERSIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-versions+=	hs-versions>=5.0.2
BUILDLINK_ABI_DEPENDS.hs-versions+=	hs-versions>=5.0.2
BUILDLINK_PKGSRCDIR.hs-versions?=	../../devel/hs-versions

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.endif	# HS_VERSIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-versions
