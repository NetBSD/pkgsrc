# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/06/01 10:56:27 drochner Exp $

BUILDLINK_TREE+=	libgnome-keyring

.if !defined(LIBGNOME_KEYRING_BUILDLINK3_MK)
LIBGNOME_KEYRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnome-keyring+=	libgnome-keyring>=2.30.1
BUILDLINK_PKGSRCDIR.libgnome-keyring?=	../../security/libgnome-keyring

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/eggdbus/buildlink3.mk"
.endif	# LIBGNOME_KEYRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnome-keyring
