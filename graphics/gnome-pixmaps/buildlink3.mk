# $NetBSD: buildlink3.mk,v 1.2 2004/05/17 21:32:34 seb Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_PIXMAPS_BUILDLINK3_MK:=	${GNOME_PIXMAPS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-pixmaps
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-pixmaps}
BUILDLINK_PACKAGES+=	gnome-pixmaps

.if !empty(GNOME_PIXMAPS_BUILDLINK3_MK:M+)
.if (${LOCALBASE} == ${X11PREFIX})
BUILDLINK_DEPENDS.gnome-pixmaps?=	gnome{2,}-pixmaps>=1.4.2
.else
BUILDLINK_DEPENDS.gnome-pixmaps?=	gnome-pixmaps>=1.4.2
.endif
BUILDLINK_PKGSRCDIR.gnome-pixmaps?=	../../graphics/gnome-pixmaps
.endif	# GNOME_PIXMAPS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
