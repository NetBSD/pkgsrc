# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:33:44 wiz Exp $

BUILDLINK_TREE+=	unibilium

.if !defined(UNIBILIUM_BUILDLINK3_MK)
UNIBILIUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unibilium+=	unibilium>=2.0.0
BUILDLINK_ABI_DEPENDS.unibilium?=		unibilium>=2.1.1nb1
BUILDLINK_PKGSRCDIR.unibilium?=		../../devel/unibilium
.endif	# UNIBILIUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-unibilium
