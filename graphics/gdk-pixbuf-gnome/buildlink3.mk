# $NetBSD: buildlink3.mk,v 1.1 2004/02/15 12:48:34 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GDK_PIXBUF_GNOME_BUILDLINK3_MK:=	${GDK_PIXBUF_GNOME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gdk-pixbuf-gnome
.endif

.if !empty(GDK_PIXBUF_GNOME_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gdk-pixbuf-gnome
BUILDLINK_DEPENDS.gdk-pixbuf-gnome+=	gdk-pixbuf-gnome>=0.22.0nb2
BUILDLINK_PKGSRCDIR.gdk-pixbuf-gnome?=	../../graphics/gdk-pixbuf-gnome

.  include "../../graphics/gdk-pixbuf/buildlink3.mk"
.  include "../../x11/gnome-libs/buildlink3.mk"
.endif # GDK_PIXBUF_GNOME_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
