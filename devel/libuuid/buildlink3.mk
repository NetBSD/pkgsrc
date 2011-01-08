# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/08 20:40:33 markd Exp $

BUILDLINK_TREE+=	libuuid

.if !defined(LIBUUID_BUILDLINK3_MK)
LIBUUID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libuuid+=	libuuid>=2.18
BUILDLINK_PKGSRCDIR.libuuid?=	../../devel/libuuid
.endif	# LIBUUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libuuid
