# $NetBSD: buildlink3.mk,v 1.35 2018/11/29 11:20:18 prlw1 Exp $

BUILDLINK_TREE+=	libcanberra

.if !defined(LIBCANBERRA_BUILDLINK3_MK)
LIBCANBERRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcanberra+=	libcanberra>=0.10
BUILDLINK_ABI_DEPENDS.libcanberra+=	libcanberra>=0.30
BUILDLINK_PKGSRCDIR.libcanberra?=	../../audio/libcanberra

pkgbase := libcanberra
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libcanberra:Mgtk)
.include "../../x11/gtk2/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.libcanberra:Mgtk3)
.include "../../x11/gtk3/buildlink3.mk"
.endif
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.endif # LIBCANBERRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcanberra
