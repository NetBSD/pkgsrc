# $NetBSD: buildlink3.mk,v 1.5 2012/03/03 00:12:21 wiz Exp $

BUILDLINK_TREE+=	gnome-settings-daemon

.if !defined(GNOME_SETTINGS_DAEMON_BUILDLINK3_MK)
GNOME_SETTINGS_DAEMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-settings-daemon+=	gnome-settings-daemon>=2.22.0
BUILDLINK_ABI_DEPENDS.gnome-settings-daemon?=	gnome-settings-daemon>=2.32.1nb9
BUILDLINK_PKGSRCDIR.gnome-settings-daemon?=	../../sysutils/gnome-settings-daemon

.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif # GNOME_SETTINGS_DAEMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-settings-daemon
