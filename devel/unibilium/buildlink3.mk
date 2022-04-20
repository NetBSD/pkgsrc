# $NetBSD: buildlink3.mk,v 1.1 2022/04/20 17:33:05 nia Exp $

BUILDLINK_TREE+=	unibilium

.if !defined(UNIBILIUM_BUILDLINK3_MK)
UNIBILIUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unibilium+=	unibilium>=2.0.0
BUILDLINK_PKGSRCDIR.unibilium?=		../../devel/unibilium
.endif	# UNIBILIUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-unibilium
