# $NetBSD: buildlink3.mk,v 1.15 2012/05/07 01:53:34 dholland Exp $

BUILDLINK_TREE+=	jpeg

.if !defined(JPEG_BUILDLINK3_MK)
JPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jpeg+=	jpeg>=8nb1
#BUILDLINK_ABI_DEPENDS.jpeg+=	jpeg>=8nb1
BUILDLINK_ABI_DEPENDS.jpeg+=	jpeg>=8nb1
BUILDLINK_PKGSRCDIR.jpeg?=	../../graphics/jpeg
.endif # JPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-jpeg
