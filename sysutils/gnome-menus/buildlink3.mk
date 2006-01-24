# $NetBSD: buildlink3.mk,v 1.4 2006/01/24 07:32:34 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_MENUS_BUILDLINK3_MK:=	${GNOME_MENUS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-menus
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-menus}
BUILDLINK_PACKAGES+=	gnome-menus

.if !empty(GNOME_MENUS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-menus+=		gnome-menus>=2.12.0
BUILDLINK_RECOMMENDED.gnome-menus?=	gnome-menus>=2.12.0nb2
BUILDLINK_PKGSRCDIR.gnome-menus?=	../../sysutils/gnome-menus
.endif	# GNOME_MENUS_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
