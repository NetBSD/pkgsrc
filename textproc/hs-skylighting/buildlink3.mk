# $NetBSD: buildlink3.mk,v 1.1 2020/01/17 17:32:25 pho Exp $

BUILDLINK_TREE+=	hs-skylighting

.if !defined(HS_SKYLIGHTING_BUILDLINK3_MK)
HS_SKYLIGHTING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-skylighting+=	hs-skylighting>=0.8.3
BUILDLINK_ABI_DEPENDS.hs-skylighting+=	hs-skylighting>=0.8.3
BUILDLINK_PKGSRCDIR.hs-skylighting?=	../../textproc/hs-skylighting

.include "../../textproc/hs-skylighting-core/buildlink3.mk"
.endif	# HS_SKYLIGHTING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-skylighting
