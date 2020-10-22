# $NetBSD: buildlink3.mk,v 1.2 2020/10/22 20:19:39 tnn Exp $

BUILDLINK_TREE+=	libcbor

.if !defined(LIBCBOR_BUILDLINK3_MK)
LIBCBOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcbor+=	libcbor>=0.8.0
BUILDLINK_PKGSRCDIR.libcbor?=	../../devel/libcbor
.endif	# LIBCBOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcbor
