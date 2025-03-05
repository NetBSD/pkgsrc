# $NetBSD: buildlink3.mk,v 1.7 2025/03/05 03:40:03 pho Exp $

BUILDLINK_TREE+=	hs-skylighting-format-ansi

.if !defined(HS_SKYLIGHTING_FORMAT_ANSI_BUILDLINK3_MK)
HS_SKYLIGHTING_FORMAT_ANSI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-skylighting-format-ansi+=	hs-skylighting-format-ansi>=0.1
BUILDLINK_ABI_DEPENDS.hs-skylighting-format-ansi+=	hs-skylighting-format-ansi>=0.1nb6
BUILDLINK_PKGSRCDIR.hs-skylighting-format-ansi?=	../../textproc/hs-skylighting-format-ansi

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-colour/buildlink3.mk"
.include "../../textproc/hs-skylighting-core/buildlink3.mk"
.endif	# HS_SKYLIGHTING_FORMAT_ANSI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-skylighting-format-ansi
