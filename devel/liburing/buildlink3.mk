# $NetBSD: buildlink3.mk,v 1.2 2026/05/06 19:17:19 vins Exp $

BUILDLINK_TREE+=	liburing

.if !defined(LIBURING_BUILDLINK3_MK)
LIBURING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liburing+=	liburing>=2.14
BUILDLINK_PKGSRCDIR.liburing?=		../../devel/liburing
.endif	# LIBURING_BUILDLINK3_MK

BUILDLINK_TREE+=	-liburing
