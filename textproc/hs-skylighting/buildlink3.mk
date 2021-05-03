# $NetBSD: buildlink3.mk,v 1.3 2021/05/03 19:01:17 pho Exp $

BUILDLINK_TREE+=	hs-skylighting

.if !defined(HS_SKYLIGHTING_BUILDLINK3_MK)
HS_SKYLIGHTING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-skylighting+=	hs-skylighting>=0.10.5
BUILDLINK_ABI_DEPENDS.hs-skylighting+=	hs-skylighting>=0.10.5.1nb1
BUILDLINK_PKGSRCDIR.hs-skylighting?=	../../textproc/hs-skylighting

.include "../../textproc/hs-skylighting-core/buildlink3.mk"
.endif	# HS_SKYLIGHTING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-skylighting
