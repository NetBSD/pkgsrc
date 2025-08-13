# $NetBSD: buildlink3.mk,v 1.15 2025/08/13 11:07:29 pho Exp $

BUILDLINK_TREE+=	hs-cmark-gfm

.if !defined(HS_CMARK_GFM_BUILDLINK3_MK)
HS_CMARK_GFM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cmark-gfm+=	hs-cmark-gfm>=0.2.6
BUILDLINK_ABI_DEPENDS.hs-cmark-gfm+=	hs-cmark-gfm>=0.2.6nb5
BUILDLINK_PKGSRCDIR.hs-cmark-gfm?=	../../textproc/hs-cmark-gfm

.include "../../textproc/cmark-gfm/buildlink3.mk"
.endif	# HS_CMARK_GFM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cmark-gfm
