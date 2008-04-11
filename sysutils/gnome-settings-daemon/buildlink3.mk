# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/04/11 19:12:09 drochner Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GNOME_SETTINGS_DAEMON_BUILDLINK3_MK:=	${GNOME_SETTINGS_DAEMON_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gnome-settings-daemon
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-settings-daemon}
BUILDLINK_PACKAGES+=	gnome-settings-daemon
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-settings-daemon

.if ${GNOME_SETTINGS_DAEMON_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gnome-settings-daemon+=	gnome-settings-daemon>=2.22.0
BUILDLINK_PKGSRCDIR.gnome-settings-daemon?=	../../sysutils/gnome-settings-daemon
.endif	# GNOME_SETTINGS_DAEMON_BUILDLINK3_MK

.include "../../sysutils/dbus-glib/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
