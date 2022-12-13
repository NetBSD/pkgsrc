# $NetBSD: buildlink3.mk,v 1.2 2022/12/13 12:46:24 jperkin Exp $

BUILDLINK_TREE+=	libuuid

.if !defined(LIBUUID_BUILDLINK3_MK)
LIBUUID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libuuid+=	libuuid>=2.18
BUILDLINK_PKGSRCDIR.libuuid?=	../../devel/libuuid
BUILDLINK_INCDIRS.libuuid+=	include/uuid
.endif	# LIBUUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libuuid
