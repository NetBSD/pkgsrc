# $NetBSD: buildlink3.mk,v 1.1 2008/12/02 19:59:08 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_MOUNT_BUILDLINK3_MK:=	${GNOME_MOUNT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gnome-mount
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-mount}
BUILDLINK_PACKAGES+=	gnome-mount
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-mount

.if ${GNOME_MOUNT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gnome-mount+=	gnome-mount>=0.8nb1
BUILDLINK_PKGSRCDIR.gnome-mount?=	../../sysutils/gnome-mount
.endif	# GNOME_MOUNT_BUILDLINK3_MK

#.include "../../security/gnome-keyring/buildlink3.mk"
#.include "../../sysutils/dbus-glib/buildlink3.mk"
#.include "../../sysutils/hal/buildlink3.mk"
#.include "../../sysutils/libnotify/buildlink3.mk"
#.include "../../sysutils/nautilus/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
