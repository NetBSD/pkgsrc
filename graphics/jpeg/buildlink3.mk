# $NetBSD: buildlink3.mk,v 1.13 2010/01/17 18:41:54 tnn Exp $

BUILDLINK_TREE+=	jpeg

.if !defined(JPEG_BUILDLINK3_MK)
JPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jpeg+=	jpeg>=8
#BUILDLINK_ABI_DEPENDS.jpeg+=	jpeg>=8
BUILDLINK_ABI_DEPENDS.jpeg?=	jpeg>=8
BUILDLINK_PKGSRCDIR.jpeg?=	../../graphics/jpeg
.endif # JPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-jpeg
