# $NetBSD: buildlink3.mk,v 1.50 2020/11/05 09:06:43 ryoon Exp $

BUILDLINK_TREE+=	libpurple

.if !defined(LIBPURPLE_BUILDLINK3_MK)
LIBPURPLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpurple+=	libpurple>=2.11.0
BUILDLINK_ABI_DEPENDS.libpurple+=	libpurple>=2.14.1nb3
BUILDLINK_PKGSRCDIR.libpurple?=		../../chat/libpurple

pkgbase := libpurple
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libpurple:Mdbus}
.  include "../../sysutils/dbus/buildlink3.mk"
.  include "../../sysutils/dbus-glib/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libpurple:Mfarstream}
.  include "../../chat/farstream/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libpurple:Mgstreamer}
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
