# $NetBSD: buildlink3.mk,v 1.1 2004/04/26 05:55:21 snj Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_PIXMAPS_BUILDLINK3_MK:=	${GNOME_PIXMAPS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-pixmaps
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-pixmaps}
BUILDLINK_PACKAGES+=	gnome-pixmaps

.if !empty(GNOME_PIXMAPS_BUILDLINK3_MK:M+)
.if (${LOCALBASE} == ${X11PREFIX})
BUILDLINK_PKGBASE.gnome-pixmaps?=	gnome{2,}-pixmaps
BUILDLINK_DEPENDS.gnome-pixmaps?=	gnome{2,}-pixmaps>=1.4.2
.else
BUILDLINK_DEPENDS.gnome-pixmaps?=	gnome-pixmaps>=1.4.2
.endif
BUILDLINK_PKGSRCDIR.gnome-pixmaps?=	../../graphics/gnome-pixmaps
.endif	# GNOME_PIXMAPS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
