# $NetBSD: buildlink3.mk,v 1.1 2017/06/22 10:56:09 nros Exp $

BUILDLINK_TREE+=	unbound

.if !defined(UNBOUND_BUILDLINK3_MK)
UNBOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unbound+=	unbound>=1.6.0
BUILDLINK_PKGSRCDIR.unbound?=	../../net/unbound

.endif	# UNBOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-unbound
