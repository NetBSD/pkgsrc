# $NetBSD: buildlink3.mk,v 1.2 2023/02/07 01:41:14 pho Exp $

BUILDLINK_TREE+=	hs-skylighting-format-latex

.if !defined(HS_SKYLIGHTING_FORMAT_LATEX_BUILDLINK3_MK)
HS_SKYLIGHTING_FORMAT_LATEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-skylighting-format-latex+=	hs-skylighting-format-latex>=0.1
BUILDLINK_ABI_DEPENDS.hs-skylighting-format-latex+=	hs-skylighting-format-latex>=0.1nb1
BUILDLINK_PKGSRCDIR.hs-skylighting-format-latex?=	../../textproc/hs-skylighting-format-latex

.include "../../textproc/hs-skylighting-core/buildlink3.mk"
.endif	# HS_SKYLIGHTING_FORMAT_LATEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-skylighting-format-latex
