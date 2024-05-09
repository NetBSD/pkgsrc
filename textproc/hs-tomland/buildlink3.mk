# $NetBSD: buildlink3.mk,v 1.2 2024/05/09 01:32:48 pho Exp $

BUILDLINK_TREE+=	hs-tomland

.if !defined(HS_TOMLAND_BUILDLINK3_MK)
HS_TOMLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tomland+=	hs-tomland>=1.3.3
BUILDLINK_ABI_DEPENDS.hs-tomland+=	hs-tomland>=1.3.3.2nb1
BUILDLINK_PKGSRCDIR.hs-tomland?=	../../textproc/hs-tomland

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-validation-selective/buildlink3.mk"
.endif	# HS_TOMLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tomland
