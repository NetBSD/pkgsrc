# $NetBSD: buildlink3.mk,v 1.4 2026/07/13 04:36:01 wiz Exp $

BUILDLINK_TREE+=	SDL3_image

.if !defined(SDL3_IMAGE_BUILDLINK3_MK)
SDL3_IMAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL3_image+=	SDL3_image>=3.2.0
BUILDLINK_ABI_DEPENDS.SDL3_image+=	SDL3_image>=3.4.0nb1
BUILDLINK_PKGSRCDIR.SDL3_image?=	../../graphics/SDL3_image
BUILDLINK_INCDIRS.SDL3_image?=		include/SDL3

.include "../../devel/SDL3/buildlink3.mk"
.endif # SDL3_IMAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL3_image
