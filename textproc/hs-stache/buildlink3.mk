# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 17:55:27 pho Exp $

BUILDLINK_TREE+=	hs-stache

.if !defined(HS_STACHE_BUILDLINK3_MK)
HS_STACHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stache+=	hs-stache>=2.3.4
BUILDLINK_ABI_DEPENDS.hs-stache+=	hs-stache>=2.3.4
BUILDLINK_PKGSRCDIR.hs-stache?=		../../textproc/hs-stache

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_STACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stache
