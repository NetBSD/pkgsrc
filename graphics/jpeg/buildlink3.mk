# $NetBSD: buildlink3.mk,v 1.12 2009/08/26 19:56:41 sno Exp $

BUILDLINK_TREE+=	jpeg

.if !defined(JPEG_BUILDLINK3_MK)
JPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jpeg+=	jpeg>=7
#BUILDLINK_ABI_DEPENDS.jpeg+=	jpeg>=7
BUILDLINK_ABI_DEPENDS.jpeg?=	jpeg>=7
BUILDLINK_PKGSRCDIR.jpeg?=	../../graphics/jpeg
.endif # JPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-jpeg
