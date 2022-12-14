# $NetBSD: buildlink3.mk,v 1.3 2022/12/14 00:27:04 wiz Exp $

BUILDLINK_TREE+=	libuuid

.if !defined(LIBUUID_BUILDLINK3_MK)
LIBUUID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libuuid+=	libuuid>=2.18
BUILDLINK_PKGSRCDIR.libuuid?=	../../devel/libuuid
.endif	# LIBUUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libuuid
