# $NetBSD: buildlink3.mk,v 1.5 2025/08/13 11:06:34 pho Exp $

BUILDLINK_TREE+=	hs-colourista

.if !defined(HS_COLOURISTA_BUILDLINK3_MK)
HS_COLOURISTA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-colourista+=	hs-colourista>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-colourista+=	hs-colourista>=0.1.0.2nb4
BUILDLINK_PKGSRCDIR.hs-colourista?=	../../devel/hs-colourista

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.endif	# HS_COLOURISTA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-colourista
