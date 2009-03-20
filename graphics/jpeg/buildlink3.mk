# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:41 joerg Exp $

BUILDLINK_TREE+=	jpeg

.if !defined(JPEG_BUILDLINK3_MK)
JPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jpeg+=	jpeg>=6b
BUILDLINK_ABI_DEPENDS.jpeg+=	jpeg>=6bnb2
BUILDLINK_PKGSRCDIR.jpeg?=	../../graphics/jpeg
.endif # JPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-jpeg
