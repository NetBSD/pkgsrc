# $NetBSD: buildlink3.mk,v 1.1 2020/02/07 12:25:49 ryoon Exp $

BUILDLINK_TREE+=	spice-gtk

.if !defined(SPICE_GTK_BUILDLINK3_MK)
SPICE_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spice-gtk+=	spice-gtk>=0.37
BUILDLINK_PKGSRCDIR.spice-gtk?=		../../sysutils/spice-gtk

.include "../../audio/libopus/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/spice-protocol/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.endif	# SPICE_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-spice-gtk
