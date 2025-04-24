# $NetBSD: buildlink3.mk,v 1.29 2025/04/24 14:15:23 wiz Exp $

BUILDLINK_TREE+=	gnome-online-accounts

.if !defined(GNOME_ONLINE_ACCOUNTS_BUILDLINK3_MK)
GNOME_ONLINE_ACCOUNTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-online-accounts+=	gnome-online-accounts>=3.29.1
BUILDLINK_ABI_DEPENDS.gnome-online-accounts?=	gnome-online-accounts>=3.36.0nb28
BUILDLINK_PKGSRCDIR.gnome-online-accounts?=	../../net/gnome-online-accounts

.include "../../x11/gtk3/buildlink3.mk"
.endif	# GNOME_ONLINE_ACCOUNTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-online-accounts
