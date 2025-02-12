# $NetBSD: buildlink3.mk,v 1.20 2025/02/12 06:44:53 ryoon Exp $

BUILDLINK_TREE+=	fna

.if !defined(FNA_BUILDLINK3_MK)
FNA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fna+=	fna>=22.05
BUILDLINK_ABI_DEPENDS.fna?=	fna>=22.05nb13
BUILDLINK_PKGSRCDIR.fna?=	../../games/fna

.include "../../graphics/mojoshader/buildlink3.mk"
.include "../../graphics/fna3d/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.endif	# FNA_BUILDLINK3_MK

BUILDLINK_TREE+=	-fna
