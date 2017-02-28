# $NetBSD: buildlink3.mk,v 1.5 2017/02/28 14:40:47 ryoon Exp $

BUILDLINK_TREE+=	libwebp

.if !defined(LIBWEBP_BUILDLINK3_MK)
LIBWEBP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwebp+=	libwebp>=0.2.0
BUILDLINK_ABI_DEPENDS.libwebp+=	libwebp>=0.6.0
BUILDLINK_PKGSRCDIR.libwebp?=	../../graphics/libwebp

.endif	# LIBWEBP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwebp
