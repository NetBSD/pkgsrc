# $NetBSD: buildlink3.mk,v 1.48 2020/06/02 08:22:32 adam Exp $

BUILDLINK_TREE+=	libpurple

.if !defined(LIBPURPLE_BUILDLINK3_MK)
LIBPURPLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpurple+=	libpurple>=2.11.0
BUILDLINK_ABI_DEPENDS.libpurple+=	libpurple>=2.13.0nb13
BUILDLINK_PKGSRCDIR.libpurple?=		../../chat/libpurple

pkgbase := libpurple
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libpurple:Mdbus)
.  include "../../sysutils/dbus/buildlink3.mk"
.  include "../../sysutils/dbus-glib/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.libpurple:Mfarstream)
.  include "../../chat/farstream/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.libpurple:Mgstreamer)
.  include "../../multimedia/gstreamer1/buildlink3.mk"
.  include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif
.if empty(PKG_BUILD_OPTIONS.libpurple:Mgnutls)
.  include "../../devel/nss/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBPURPLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpurple
