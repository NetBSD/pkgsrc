# $NetBSD: buildlink3.mk,v 1.1 2016/06/14 06:59:43 kamil Exp $

BUILDLINK_TREE+=	keystone

.if !defined(KEYSTONE_BUILDLINK3_MK)
KEYSTONE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.keystone+=	keystone>=0.9
BUILDLINK_PKGSRCDIR.keystone?=		../../emulators/keystone
.endif	# KEYSTONE_BUILDLINK3_MK

BUILDLINK_TREE+=	-keystone
