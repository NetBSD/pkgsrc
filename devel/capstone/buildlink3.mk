# $NetBSD: buildlink3.mk,v 1.2 2016/06/13 01:51:04 kamil Exp $

BUILDLINK_TREE+=	capstone

.if !defined(CAPSTONE_BUILDLINK3_MK)
CAPSTONE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.capstone+=	capstone>=3.0
BUILDLINK_PKGSRCDIR.capstone?=		../../devel/capstone
.endif	# CAPSTONE_BUILDLINK3_MK

BUILDLINK_TREE+=	-capstone
