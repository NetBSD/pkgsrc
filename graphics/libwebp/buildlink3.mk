# $NetBSD: buildlink3.mk,v 1.4 2016/01/10 10:22:32 adam Exp $

BUILDLINK_TREE+=	libwebp

.if !defined(LIBWEBP_BUILDLINK3_MK)
LIBWEBP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwebp+=	libwebp>=0.2.0
BUILDLINK_ABI_DEPENDS.libwebp+=	libwebp>=0.5.0
BUILDLINK_PKGSRCDIR.libwebp?=	../../graphics/libwebp

.endif	# LIBWEBP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwebp
