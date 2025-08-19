# $NetBSD: buildlink3.mk,v 1.3 2025/08/19 10:15:19 wiz Exp $

BUILDLINK_TREE+=	keystone

.if !defined(KEYSTONE_BUILDLINK3_MK)
KEYSTONE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.keystone+=	keystone>=0.9
BUILDLINK_ABI_DEPENDS.keystone?=	keystone>=0.9.2nb2
BUILDLINK_PKGSRCDIR.keystone?=		../../emulators/keystone
.endif	# KEYSTONE_BUILDLINK3_MK

BUILDLINK_TREE+=	-keystone
