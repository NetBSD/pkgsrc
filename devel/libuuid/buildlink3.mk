# $NetBSD: buildlink3.mk,v 1.4 2023/08/14 05:24:12 wiz Exp $

BUILDLINK_TREE+=	libuuid

.if !defined(LIBUUID_BUILDLINK3_MK)
LIBUUID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libuuid+=	libuuid>=2.18
BUILDLINK_ABI_DEPENDS.libuuid?=	libuuid>=2.32.1nb2
BUILDLINK_PKGSRCDIR.libuuid?=	../../devel/libuuid
.endif	# LIBUUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libuuid
