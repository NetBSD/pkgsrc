# $NetBSD: buildlink3.mk,v 1.16 2013/01/24 21:49:18 adam Exp $

BUILDLINK_TREE+=	jpeg

.if !defined(JPEG_BUILDLINK3_MK)
JPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jpeg+=	jpeg>=9
BUILDLINK_ABI_DEPENDS.jpeg+=	jpeg>=9
BUILDLINK_PKGSRCDIR.jpeg?=	../../graphics/jpeg
.endif # JPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-jpeg
