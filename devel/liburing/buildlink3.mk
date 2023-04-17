# $NetBSD: buildlink3.mk,v 1.1 2023/04/17 21:32:54 gutteridge Exp $

BUILDLINK_TREE+=	liburing

.if !defined(LIBURING_BUILDLINK3_MK)
LIBURING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liburing+=	liburing>=2.3
BUILDLINK_PKGSRCDIR.liburing?=		../../devel/liburing
.endif	# LIBURING_BUILDLINK3_MK

BUILDLINK_TREE+=	-liburing
