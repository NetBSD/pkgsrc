# $NetBSD: buildlink3.mk,v 1.1 2022/07/17 19:32:46 wiz Exp $

BUILDLINK_TREE+=	libhighway

.if !defined(LIBHIGHWAY_BUILDLINK3_MK)
LIBHIGHWAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhighway+=	libhighway>=0.12.2
BUILDLINK_PKGSRCDIR.libhighway?=	../../graphics/libhighway

.endif	# LIBHIGHWAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhighway
