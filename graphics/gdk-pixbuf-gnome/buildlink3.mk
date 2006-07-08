# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:10:51 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GDK_PIXBUF_GNOME_BUILDLINK3_MK:=	${GDK_PIXBUF_GNOME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gdk-pixbuf-gnome
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngdk-pixbuf-gnome}
BUILDLINK_PACKAGES+=	gdk-pixbuf-gnome
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gdk-pixbuf-gnome

.if !empty(GDK_PIXBUF_GNOME_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gdk-pixbuf-gnome+=	gdk-pixbuf-gnome>=0.22.0nb2
BUILDLINK_ABI_DEPENDS.gdk-pixbuf-gnome?=	gdk-pixbuf-gnome>=0.22.0nb6
BUILDLINK_PKGSRCDIR.gdk-pixbuf-gnome?=	../../graphics/gdk-pixbuf-gnome
.endif	# GDK_PIXBUF_GNOME_BUILDLINK3_MK

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
