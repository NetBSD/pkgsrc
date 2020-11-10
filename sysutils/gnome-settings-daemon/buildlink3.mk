# $NetBSD: buildlink3.mk,v 1.9 2020/11/10 01:21:24 nia Exp $

BUILDLINK_TREE+=	gnome-settings-daemon

.if !defined(GNOME_SETTINGS_DAEMON_BUILDLINK3_MK)
GNOME_SETTINGS_DAEMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-settings-daemon+=	gnome-settings-daemon>=3.16.0
BUILDLINK_ABI_DEPENDS.gnome-settings-daemon+=	gnome-settings-daemon>=3.16.1nb13
BUILDLINK_PKGSRCDIR.gnome-settings-daemon?=	../../sysutils/gnome-settings-daemon
.endif # GNOME_SETTINGS_DAEMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-settings-daemon
