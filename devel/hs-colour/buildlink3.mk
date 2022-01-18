# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:05 pho Exp $

BUILDLINK_TREE+=	hs-colour

.if !defined(HS_COLOUR_BUILDLINK3_MK)
HS_COLOUR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-colour+=	hs-colour>=2.3.5
BUILDLINK_ABI_DEPENDS.hs-colour+=	hs-colour>=2.3.5nb2
BUILDLINK_PKGSRCDIR.hs-colour?=		../../devel/hs-colour
.endif	# HS_COLOUR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-colour
