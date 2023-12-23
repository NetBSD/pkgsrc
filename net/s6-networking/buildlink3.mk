# $NetBSD: buildlink3.mk,v 1.5 2023/12/23 20:11:48 schmonz Exp $

BUILDLINK_TREE+=	s6-networking

.if !defined(S6_NETWORKING_BUILDLINK3_MK)
S6_NETWORKING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.s6-networking+=	s6-networking>=2.7.0.1
BUILDLINK_PKGSRCDIR.s6-networking?=	../../net/s6-networking
BUILDLINK_INCDIRS.s6-networking+=	include/s6-networking
BUILDLINK_LIBDIRS.s6-networking+=	lib/s6-networking
BUILDLINK_DEPMETHOD.s6-networking?=	build
.endif	# S6_NETWORKING_BUILDLINK3_MK

BUILDLINK_TREE+=	-s6-networking
