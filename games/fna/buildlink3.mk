# $NetBSD: buildlink3.mk,v 1.26 2026/09/27 11:36:16 tnn Exp $

BUILDLINK_TREE+=	fna

.if !defined(FNA_BUILDLINK3_MK)
FNA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fna+=	fna>=22.05
BUILDLINK_ABI_DEPENDS.fna?=	fna>=22.05nb19
BUILDLINK_PKGSRCDIR.fna?=	../../games/fna

.include "../../graphics/mojoshader/buildlink3.mk"
.include "../../graphics/fna3d/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.endif	# FNA_BUILDLINK3_MK

BUILDLINK_TREE+=	-fna
