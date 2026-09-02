# $NetBSD: buildlink3.mk,v 1.17 2026/09/02 19:02:30 wiz Exp $

BUILDLINK_TREE+=	SDL2_image

.include "../../mk/bsd.fast.prefs.mk"
.if ${MACHINE_PLATFORM:MDarwin-*-powerpc*}
# This defines SDL2_IMAGE_BUILDLINK3_MK.
.  include "../../graphics/SDL2_image-legacy/buildlink3.mk"
.endif

.if !defined(SDL2_IMAGE_BUILDLINK3_MK)
SDL2_IMAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2_image+=	SDL2_image>=2.0.0
BUILDLINK_ABI_DEPENDS.SDL2_image?=	SDL2_image>=2.6.3nb9
BUILDLINK_PKGSRCDIR.SDL2_image?=	../../graphics/SDL2_image
BUILDLINK_INCDIRS.SDL2_image?=		include/SDL2

.include "../../devel/SDL2/buildlink3.mk"
.endif # SDL2_IMAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2_image
