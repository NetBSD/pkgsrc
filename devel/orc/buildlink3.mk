# $NetBSD: buildlink3.mk,v 1.3 2024/01/28 07:14:17 adam Exp $

BUILDLINK_TREE+=	orc

.if !defined(ORC_BUILDLINK3_MK)
ORC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.orc+=	orc>=0.4.6
BUILDLINK_ABI_DEPENDS.orc+=	orc>=0.4.34nb1
BUILDLINK_PKGSRCDIR.orc?=	../../devel/orc
.endif	# ORC_BUILDLINK3_MK

BUILDLINK_TREE+=	-orc
