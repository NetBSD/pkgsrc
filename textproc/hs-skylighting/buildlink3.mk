# $NetBSD: buildlink3.mk,v 1.17 2024/05/09 01:32:46 pho Exp $

BUILDLINK_TREE+=	hs-skylighting

.if !defined(HS_SKYLIGHTING_BUILDLINK3_MK)
HS_SKYLIGHTING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-skylighting+=	hs-skylighting>=0.14.1
BUILDLINK_ABI_DEPENDS.hs-skylighting+=	hs-skylighting>=0.14.1.1nb1
BUILDLINK_PKGSRCDIR.hs-skylighting?=	../../textproc/hs-skylighting

.include "../../textproc/hs-skylighting-core/buildlink3.mk"
.include "../../textproc/hs-skylighting-format-ansi/buildlink3.mk"
.include "../../textproc/hs-skylighting-format-blaze-html/buildlink3.mk"
.include "../../textproc/hs-skylighting-format-context/buildlink3.mk"
.include "../../textproc/hs-skylighting-format-latex/buildlink3.mk"
.endif	# HS_SKYLIGHTING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-skylighting
