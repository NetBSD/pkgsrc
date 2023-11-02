# $NetBSD: buildlink3.mk,v 1.5 2023/11/02 06:36:21 pho Exp $

BUILDLINK_TREE+=	hs-boring

.if !defined(HS_BORING_BUILDLINK3_MK)
HS_BORING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-boring+=	hs-boring>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-boring+=	hs-boring>=0.2.1nb1
BUILDLINK_PKGSRCDIR.hs-boring?=		../../devel/hs-boring

.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_BORING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-boring
