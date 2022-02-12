# $NetBSD: buildlink3.mk,v 1.5 2022/02/12 08:50:42 pho Exp $

BUILDLINK_TREE+=	hs-wizards

.if !defined(HS_WIZARDS_BUILDLINK3_MK)
HS_WIZARDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-wizards+=	hs-wizards>=1.0.3
BUILDLINK_ABI_DEPENDS.hs-wizards+=	hs-wizards>=1.0.3nb3
BUILDLINK_PKGSRCDIR.hs-wizards?=	../../devel/hs-wizards

.include "../../devel/hs-control-monad-free/buildlink3.mk"
.endif	# HS_WIZARDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-wizards
