# $NetBSD: buildlink3.mk,v 1.2 2022/10/07 11:15:54 nros Exp $

BUILDLINK_TREE+=	libhighway

.if !defined(LIBHIGHWAY_BUILDLINK3_MK)
LIBHIGHWAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhighway+=	libhighway>=0.12.2
BUILDLINK_ABI_DEPENDS.libhighway+=	libhighway>=1.0.1
BUILDLINK_PKGSRCDIR.libhighway?=	../../graphics/libhighway

.include "../../devel/googletest/buildlink3.mk"
.endif	# LIBHIGHWAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhighway
