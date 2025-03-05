# $NetBSD: buildlink3.mk,v 1.5 2025/03/05 03:40:05 pho Exp $

BUILDLINK_TREE+=	hs-tomland

.if !defined(HS_TOMLAND_BUILDLINK3_MK)
HS_TOMLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tomland+=	hs-tomland>=1.3.3
BUILDLINK_ABI_DEPENDS.hs-tomland+=	hs-tomland>=1.3.3.3nb2
BUILDLINK_PKGSRCDIR.hs-tomland?=	../../textproc/hs-tomland

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-validation-selective/buildlink3.mk"
.endif	# HS_TOMLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tomland
