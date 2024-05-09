# $NetBSD: buildlink3.mk,v 1.12 2024/05/09 01:32:40 pho Exp $

BUILDLINK_TREE+=	hs-cmark-gfm

.if !defined(HS_CMARK_GFM_BUILDLINK3_MK)
HS_CMARK_GFM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cmark-gfm+=	hs-cmark-gfm>=0.2.6
BUILDLINK_ABI_DEPENDS.hs-cmark-gfm+=	hs-cmark-gfm>=0.2.6nb2
BUILDLINK_PKGSRCDIR.hs-cmark-gfm?=	../../textproc/hs-cmark-gfm

.include "../../textproc/cmark-gfm/buildlink3.mk"
.endif	# HS_CMARK_GFM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cmark-gfm
