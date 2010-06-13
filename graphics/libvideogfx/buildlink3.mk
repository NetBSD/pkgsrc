# $NetBSD: buildlink3.mk,v 1.13 2010/06/13 22:44:38 wiz Exp $

BUILDLINK_TREE+=	libvideogfx

.if !defined(LIBVIDEOGFX_BUILDLINK3_MK)
LIBVIDEOGFX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvideogfx+=	libvideogfx>=1.0.3
BUILDLINK_ABI_DEPENDS.libvideogfx+=	libvideogfx>=1.0.3nb6
BUILDLINK_PKGSRCDIR.libvideogfx?=	../../graphics/libvideogfx

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # LIBVIDEOGFX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvideogfx
