# $NetBSD: buildlink3.mk,v 1.2 2012/08/18 01:34:55 ryoon Exp $

BUILDLINK_TREE+=	libwebp

.if !defined(LIBWEBP_BUILDLINK3_MK)
LIBWEBP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwebp+=	libwebp>=0.2.0
BUILDLINK_ABI_DEPENDS.libwebp+=	libwebp>=0.2.0
BUILDLINK_PKGSRCDIR.libwebp?=	../../graphics/libwebp

.endif	# LIBWEBP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwebp
