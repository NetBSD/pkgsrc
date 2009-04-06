# $NetBSD: buildlink3.mk,v 1.2 2009/04/06 10:18:07 wiz Exp $

BUILDLINK_TREE+=	gtk-vnc

.if !defined(GTK_VNC_BUILDLINK3_MK)
GTK_VNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-vnc+=	gtk-vnc>=0.3.7
BUILDLINK_PKGSRCDIR.gtk-vnc?=	../../net/gtk-vnc

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTK_VNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-vnc
