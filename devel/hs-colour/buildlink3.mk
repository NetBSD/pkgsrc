# $NetBSD: buildlink3.mk,v 1.1 2019/12/29 23:57:51 pho Exp $

BUILDLINK_TREE+=	hs-colour

.if !defined(HS_COLOUR_BUILDLINK3_MK)
HS_COLOUR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-colour+=	hs-colour>=2.3.3
BUILDLINK_ABI_DEPENDS.hs-colour+=	hs-colour>=2.3.3
BUILDLINK_PKGSRCDIR.hs-colour?=	../../devel/hs-colour
.endif	# HS_COLOUR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-colour
