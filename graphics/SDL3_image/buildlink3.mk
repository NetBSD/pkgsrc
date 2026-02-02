# $NetBSD: buildlink3.mk,v 1.3 2026/02/02 08:05:19 adam Exp $

BUILDLINK_TREE+=	SDL3_image

.if !defined(SDL3_IMAGE_BUILDLINK3_MK)
SDL3_IMAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL3_image+=	SDL3_image>=3.2.0
BUILDLINK_ABI_DEPENDS.SDL3_image+=	SDL3_image>=3.2.4nb3
BUILDLINK_PKGSRCDIR.SDL3_image?=	../../graphics/SDL3_image
BUILDLINK_INCDIRS.SDL3_image?=		include/SDL3

.include "../../devel/SDL3/buildlink3.mk"
.endif # SDL3_IMAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL3_image
