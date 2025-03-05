# $NetBSD: buildlink3.mk,v 1.3 2025/03/05 03:40:03 pho Exp $

BUILDLINK_TREE+=	hs-skylighting-format-typst

.if !defined(HS_SKYLIGHTING_FORMAT_TYPST_BUILDLINK3_MK)
HS_SKYLIGHTING_FORMAT_TYPST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-skylighting-format-typst+=	hs-skylighting-format-typst>=0.1
BUILDLINK_ABI_DEPENDS.hs-skylighting-format-typst+=	hs-skylighting-format-typst>=0.1nb2
BUILDLINK_PKGSRCDIR.hs-skylighting-format-typst?=	../../textproc/hs-skylighting-format-typst

.include "../../textproc/hs-skylighting-core/buildlink3.mk"
.endif	# HS_SKYLIGHTING_FORMAT_TYPST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-skylighting-format-typst
