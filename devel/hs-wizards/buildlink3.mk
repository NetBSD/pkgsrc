# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:43:35 riastradh Exp $

BUILDLINK_TREE+=	hs-wizards

.if !defined(HS_WIZARDS_BUILDLINK3_MK)
HS_WIZARDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-wizards+=	hs-wizards>=1.0.3
BUILDLINK_ABI_DEPENDS.hs-wizards+=	hs-wizards>=1.0.3
BUILDLINK_PKGSRCDIR.hs-wizards?=	../../devel/hs-wizards
.endif	# HS_WIZARDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-wizards
