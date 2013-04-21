# $NetBSD: buildlink3.mk,v 1.1 2013/04/21 00:50:04 rodent Exp $

BUILDLINK_TREE+=	libnotify07

.if !defined(LIBNOTIFY07_BUILDLINK3_MK)
LIBNOTIFY07_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnotify07+=	libnotify07>=0.3.2
BUILDLINK_ABI_DEPENDS.libnotify07+=	libnotify07>=0.6.1
BUILDLINK_PKGSRCDIR.libnotify07?=	../../sysutils/libnotify07

pkgbase := libnotify07
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libnotify07:Mdoc)
.include "../../textproc/gtk-doc/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.libnotify07:Mintrospection)
CONFIGURE_ARGS+=	--enable-introspection=yes
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # LIBNOTIFY07_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnotify07
