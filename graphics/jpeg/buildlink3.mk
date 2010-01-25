# $NetBSD: buildlink3.mk,v 1.14 2010/01/25 08:45:34 tnn Exp $

BUILDLINK_TREE+=	jpeg

.if !defined(JPEG_BUILDLINK3_MK)
JPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jpeg+=	jpeg>=8nb1
#BUILDLINK_ABI_DEPENDS.jpeg+=	jpeg>=8nb1
BUILDLINK_ABI_DEPENDS.jpeg?=	jpeg>=8nb1
BUILDLINK_PKGSRCDIR.jpeg?=	../../graphics/jpeg
.endif # JPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-jpeg
