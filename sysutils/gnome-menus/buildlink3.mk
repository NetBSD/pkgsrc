# $NetBSD: buildlink3.mk,v 1.12 2007/06/05 05:37:01 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_MENUS_BUILDLINK3_MK:=	${GNOME_MENUS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-menus
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-menus}
BUILDLINK_PACKAGES+=	gnome-menus
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-menus

.if !empty(GNOME_MENUS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnome-menus+=		gnome-menus>=2.13.5
BUILDLINK_ABI_DEPENDS.gnome-menus?=	gnome-menus>=2.18.0nb1
BUILDLINK_PKGSRCDIR.gnome-menus?=	../../sysutils/gnome-menus
.endif	# GNOME_MENUS_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
