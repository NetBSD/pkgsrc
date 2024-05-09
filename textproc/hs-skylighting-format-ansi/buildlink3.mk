# $NetBSD: buildlink3.mk,v 1.5 2024/05/09 01:32:46 pho Exp $

BUILDLINK_TREE+=	hs-skylighting-format-ansi

.if !defined(HS_SKYLIGHTING_FORMAT_ANSI_BUILDLINK3_MK)
HS_SKYLIGHTING_FORMAT_ANSI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-skylighting-format-ansi+=	hs-skylighting-format-ansi>=0.1
BUILDLINK_ABI_DEPENDS.hs-skylighting-format-ansi+=	hs-skylighting-format-ansi>=0.1nb4
BUILDLINK_PKGSRCDIR.hs-skylighting-format-ansi?=	../../textproc/hs-skylighting-format-ansi

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-colour/buildlink3.mk"
.include "../../textproc/hs-skylighting-core/buildlink3.mk"
.endif	# HS_SKYLIGHTING_FORMAT_ANSI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-skylighting-format-ansi
