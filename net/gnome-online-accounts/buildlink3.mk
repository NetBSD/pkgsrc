# $NetBSD: buildlink3.mk,v 1.35 2026/09/02 19:03:54 wiz Exp $

BUILDLINK_TREE+=	gnome-online-accounts

.if !defined(GNOME_ONLINE_ACCOUNTS_BUILDLINK3_MK)
GNOME_ONLINE_ACCOUNTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-online-accounts+=	gnome-online-accounts>=3.58
BUILDLINK_ABI_DEPENDS.gnome-online-accounts?=	gnome-online-accounts>=3.58.1nb2
BUILDLINK_PKGSRCDIR.gnome-online-accounts?=	../../net/gnome-online-accounts

.include "../../net/libsoup3/buildlink3.mk"
.include "../../security/gcr4/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../www/librest/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.endif	# GNOME_ONLINE_ACCOUNTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-online-accounts
