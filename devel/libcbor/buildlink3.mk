# $NetBSD: buildlink3.mk,v 1.3 2026/11/15 19:37:05 wiz Exp $

BUILDLINK_TREE+=	libcbor

.if !defined(LIBCBOR_BUILDLINK3_MK)
LIBCBOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcbor+=	libcbor>=0.8.0
BUILDLINK_ABI_DEPENDS.libcbor?=	libcbor>=0.15.0
BUILDLINK_PKGSRCDIR.libcbor?=	../../devel/libcbor
.endif	# LIBCBOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcbor
