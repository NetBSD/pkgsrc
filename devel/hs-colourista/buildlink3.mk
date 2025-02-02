# $NetBSD: buildlink3.mk,v 1.3 2025/02/02 13:05:01 pho Exp $

BUILDLINK_TREE+=	hs-colourista

.if !defined(HS_COLOURISTA_BUILDLINK3_MK)
HS_COLOURISTA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-colourista+=	hs-colourista>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-colourista+=	hs-colourista>=0.1.0.2nb2
BUILDLINK_PKGSRCDIR.hs-colourista?=	../../devel/hs-colourista

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.endif	# HS_COLOURISTA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-colourista
