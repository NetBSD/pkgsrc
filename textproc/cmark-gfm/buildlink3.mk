# $NetBSD: buildlink3.mk,v 1.1 2020/01/15 06:29:58 pho Exp $

BUILDLINK_TREE+=	cmark-gfm

.if !defined(CMARK_GFM_BUILDLINK3_MK)
CMARK_GFM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cmark-gfm+=	cmark-gfm>=0.29.0.gfm.0
BUILDLINK_PKGSRCDIR.cmark-gfm?=		../../textproc/cmark-gfm
.endif	# CMARK_GFM_BUILDLINK3_MK

BUILDLINK_TREE+=	-cmark-gfm
