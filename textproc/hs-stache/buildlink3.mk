# $NetBSD: buildlink3.mk,v 1.2 2025/08/13 11:07:36 pho Exp $

BUILDLINK_TREE+=	hs-stache

.if !defined(HS_STACHE_BUILDLINK3_MK)
HS_STACHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stache+=	hs-stache>=2.3.4
BUILDLINK_ABI_DEPENDS.hs-stache+=	hs-stache>=2.3.4nb1
BUILDLINK_PKGSRCDIR.hs-stache?=		../../textproc/hs-stache

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_STACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stache
