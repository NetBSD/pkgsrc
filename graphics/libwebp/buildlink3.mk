# $NetBSD: buildlink3.mk,v 1.3 2014/10/07 16:47:11 adam Exp $

BUILDLINK_TREE+=	libwebp

.if !defined(LIBWEBP_BUILDLINK3_MK)
LIBWEBP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwebp+=	libwebp>=0.2.0
BUILDLINK_ABI_DEPENDS.libwebp+=	libwebp>=0.4.1nb1
BUILDLINK_PKGSRCDIR.libwebp?=	../../graphics/libwebp

.endif	# LIBWEBP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwebp
