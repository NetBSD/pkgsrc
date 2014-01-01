# $NetBSD: buildlink3.mk,v 1.9 2014/01/01 11:52:02 wiz Exp $

BUILDLINK_TREE+=	libgnome-keyring

.if !defined(LIBGNOME_KEYRING_BUILDLINK3_MK)
LIBGNOME_KEYRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnome-keyring+=	libgnome-keyring>=2.32.0
BUILDLINK_ABI_DEPENDS.libgnome-keyring+=	libgnome-keyring>=3.4.1nb2
BUILDLINK_PKGSRCDIR.libgnome-keyring?=	../../security/libgnome-keyring

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.endif	# LIBGNOME_KEYRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnome-keyring
