# $NetBSD: buildlink3.mk,v 1.1 2012/06/16 22:00:23 dholland Exp $

BUILDLINK_TREE+=	gnome-keyring-sharp

.if !defined(GNOME_KEYRING_SHARP_BUILDLINK3_MK)
GNOME_KEYRING_SHARP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-keyring-sharp+=	gnome-keyring-sharp>=1.0.0
BUILDLINK_PKGSRCDIR.gnome-keyring-sharp?=	../../security/gnome-keyring-sharp

.endif	# GNOME_KEYRING_SHARP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-keyring-sharp
