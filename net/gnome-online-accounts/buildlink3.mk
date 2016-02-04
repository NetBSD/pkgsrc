# $NetBSD: buildlink3.mk,v 1.1 2016/02/04 12:19:23 wiz Exp $

BUILDLINK_TREE+=	gnome-online-accounts

.if !defined(GNOME_ONLINE_ACCOUNTS_BUILDLINK3_MK)
GNOME_ONLINE_ACCOUNTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-online-accounts+=	gnome-online-accounts>=3.16.3nb2
BUILDLINK_PKGSRCDIR.gnome-online-accounts?=	../../net/gnome-online-accounts

.endif	# GNOME_ONLINE_ACCOUNTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-online-accounts
