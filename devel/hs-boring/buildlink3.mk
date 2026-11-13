# $NetBSD: buildlink3.mk,v 1.11 2026/11/13 14:38:50 pho Exp $

BUILDLINK_TREE+=	hs-boring

.if !defined(HS_BORING_BUILDLINK3_MK)
HS_BORING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-boring+=	hs-boring>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-boring+=	hs-boring>=0.2.2nb4
BUILDLINK_PKGSRCDIR.hs-boring?=		../../devel/hs-boring

.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_BORING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-boring
