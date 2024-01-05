# $NetBSD: buildlink3.mk,v 1.4 2024/01/05 11:09:53 nros Exp $

BUILDLINK_TREE+=	libhighway

.if !defined(LIBHIGHWAY_BUILDLINK3_MK)
LIBHIGHWAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhighway+=	libhighway>=1.0.7
BUILDLINK_PKGSRCDIR.libhighway?=	../../graphics/libhighway
.endif	# LIBHIGHWAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhighway
