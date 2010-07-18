# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/07/18 12:22:25 drochner Exp $

BUILDLINK_TREE+=	orc

.if !defined(ORC_BUILDLINK3_MK)
ORC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.orc+=	orc>=0.4.6
BUILDLINK_PKGSRCDIR.orc?=	../../devel/orc
.endif	# ORC_BUILDLINK3_MK

BUILDLINK_TREE+=	-orc
