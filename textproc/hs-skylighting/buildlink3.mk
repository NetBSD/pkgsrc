# $NetBSD: buildlink3.mk,v 1.12 2023/02/07 01:41:13 pho Exp $

BUILDLINK_TREE+=	hs-skylighting

.if !defined(HS_SKYLIGHTING_BUILDLINK3_MK)
HS_SKYLIGHTING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-skylighting+=	hs-skylighting>=0.13.2
BUILDLINK_ABI_DEPENDS.hs-skylighting+=	hs-skylighting>=0.13.2nb1
BUILDLINK_PKGSRCDIR.hs-skylighting?=	../../textproc/hs-skylighting

.include "../../textproc/hs-skylighting-core/buildlink3.mk"
.include "../../textproc/hs-skylighting-format-ansi/buildlink3.mk"
.include "../../textproc/hs-skylighting-format-blaze-html/buildlink3.mk"
.include "../../textproc/hs-skylighting-format-context/buildlink3.mk"
.include "../../textproc/hs-skylighting-format-latex/buildlink3.mk"
.endif	# HS_SKYLIGHTING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-skylighting
