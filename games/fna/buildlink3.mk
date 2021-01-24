# $NetBSD: buildlink3.mk,v 1.1 2021/01/24 19:07:21 maya Exp $
BUILDLINK_TREE+=	fna

.if !defined(FNA_BUILDLINK3_MK)
FNA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fna+=	fna>=21.01
BUILDLINK_PKGSRCDIR.fna?=	../../games/fna

.include "../../graphics/mojoshader/buildlink3.mk"
.include "../../graphics/fna3d/buildlink3.mk"
.include "../../lang/mono6/buildlink3.mk"
.endif	# FNA_BUILDLINK3_MK

BUILDLINK_TREE+=	-fna
