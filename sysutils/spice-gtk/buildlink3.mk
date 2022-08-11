# $NetBSD: buildlink3.mk,v 1.8 2022/08/11 05:09:17 gutteridge Exp $

BUILDLINK_TREE+=	spice-gtk

.if !defined(SPICE_GTK_BUILDLINK3_MK)
SPICE_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spice-gtk+=	spice-gtk>=0.39
BUILDLINK_ABI_DEPENDS.spice-gtk?=		spice-gtk>=0.41nb1
BUILDLINK_PKGSRCDIR.spice-gtk?=		../../sysutils/spice-gtk

.include "../../audio/libopus/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/spice-protocol/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.endif	# SPICE_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-spice-gtk
