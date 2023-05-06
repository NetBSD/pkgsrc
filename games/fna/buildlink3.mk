# $NetBSD: buildlink3.mk,v 1.13 2023/05/06 19:08:50 ryoon Exp $

BUILDLINK_TREE+=	fna

.if !defined(FNA_BUILDLINK3_MK)
FNA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fna+=	fna>=22.05
BUILDLINK_ABI_DEPENDS.fna?=	fna>=22.05nb5
BUILDLINK_PKGSRCDIR.fna?=	../../games/fna

.include "../../graphics/mojoshader/buildlink3.mk"
.include "../../graphics/fna3d/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.endif	# FNA_BUILDLINK3_MK

BUILDLINK_TREE+=	-fna
