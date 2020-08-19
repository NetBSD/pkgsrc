#	$NetBSD: buildlink3.mk,v 1.1 2020/08/19 16:25:19 riastradh Exp $

BUILDLINK_TREE+=	libcbor

.if !defined(LIBCBOR_BUILDLINK_MK)
LIBCBOR_BUILDLINK_MK:=

BUILDLINK_API_DEPENDS.libcbor+=	libcbor>=0.5.0
BUILDLINK_ABI_DEPENDS.libcbor+=	libcbor>=0.5.0
BUILDLINK_PKGSRCDIR.libcbor?=	../../devel/libcbor

.endif # LIBCBOR_BUILDLINK_MK

BUILDLINK_TREE+=	-libcbor
