# $NetBSD: buildlink3.mk,v 1.35 2012/09/07 19:16:25 adam Exp $

BUILDLINK_TREE+=	libgnome

.if !defined(LIBGNOME_BUILDLINK3_MK)
LIBGNOME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.8.0
BUILDLINK_ABI_DEPENDS.libgnome+=	libgnome>=2.32.1nb9
BUILDLINK_PKGSRCDIR.libgnome?=	../../devel/libgnome

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := libgnome
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.libgnome:Mesound)
.include "../../audio/esound/buildlink3.mk"
.endif

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif # LIBGNOME_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnome
