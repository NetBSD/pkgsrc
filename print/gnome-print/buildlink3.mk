# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:18:05 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_PRINT_BUILDLINK3_MK:=	${GNOME_PRINT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-print
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-print}
BUILDLINK_PACKAGES+=	gnome-print

.if !empty(GNOME_PRINT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-print+=	gnome-print>=0.36nb4
BUILDLINK_RECOMMENDED.gnome-print+=	gnome-print>=0.36nb5
BUILDLINK_PKGSRCDIR.gnome-print?=	../../print/gnome-print
.endif	# GNOME_PRINT_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../textproc/libunicode/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
