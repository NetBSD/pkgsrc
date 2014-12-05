# $NetBSD: buildlink3.mk,v 1.1 2014/12/05 11:51:58 wiz Exp $

BUILDLINK_TREE+=	capstone

.if !defined(CAPSTONE_BUILDLINK3_MK)
CAPSTONE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.capstone+=	capstone>=3.0
BUILDLINK_PKGSRCDIR.capstone?=	../../devel/capstone
.endif	# CAPSTONE_BUILDLINK3_MK

BUILDLINK_TREE+=	-capstone
