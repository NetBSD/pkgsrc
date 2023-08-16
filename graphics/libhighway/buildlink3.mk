# $NetBSD: buildlink3.mk,v 1.3 2023/08/16 15:20:49 nia Exp $

BUILDLINK_TREE+=	libhighway

.if !defined(LIBHIGHWAY_BUILDLINK3_MK)
LIBHIGHWAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhighway+=	libhighway>=0.12.2
BUILDLINK_ABI_DEPENDS.libhighway+=	libhighway>=1.0.1
BUILDLINK_PKGSRCDIR.libhighway?=	../../graphics/libhighway
.endif	# LIBHIGHWAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhighway
