# $NetBSD: buildlink3.mk,v 1.5 2004/10/03 00:14:50 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GDK_PIXBUF_BUILDLINK3_MK:=	${GDK_PIXBUF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gdk-pixbuf
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngdk-pixbuf}
BUILDLINK_PACKAGES+=	gdk-pixbuf

.if !empty(GDK_PIXBUF_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gdk-pixbuf+=		gdk-pixbuf>=0.22.0nb2
BUILDLINK_RECOMMENDED.gdk-pixbuf+=	gdk-pixbuf>=0.22.0nb3
BUILDLINK_PKGSRCDIR.gdk-pixbuf?=	../../graphics/gdk-pixbuf
BUILDLINK_CPPFLAGS.gdk-pixbuf+= \
	-I${BUILDLINK_PREFIX.gdk-pixbuf}/include/gdk-pixbuf-1.0
.endif	# GDK_PIXBUF_BUILDLINK3_MK

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
