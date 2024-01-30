# $NetBSD: buildlink3.mk,v 1.11 2024/01/30 14:22:07 ryoon Exp $

BUILDLINK_TREE+=	SDL2_image

.if !defined(SDL2_IMAGE_BUILDLINK3_MK)
SDL2_IMAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_image+=	SDL2_image>=2.0.0
BUILDLINK_ABI_DEPENDS.SDL2_image+=	SDL2_image>=2.6.3nb2
BUILDLINK_PKGSRCDIR.SDL2_image?=	../../graphics/SDL2_image
BUILDLINK_INCDIRS.SDL2_image?=		include/SDL2

.include "../../devel/SDL2/buildlink3.mk"
.endif # SDL2_IMAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_image
