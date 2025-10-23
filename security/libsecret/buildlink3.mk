# $NetBSD: buildlink3.mk,v 1.8 2025/10/23 20:39:08 wiz Exp $

BUILDLINK_TREE+=	libsecret

.if !defined(LIBSECRET_BUILDLINK3_MK)
LIBSECRET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsecret+=	libsecret>=0.12
BUILDLINK_ABI_DEPENDS.libsecret+=	libsecret>=0.20.5nb2
BUILDLINK_PKGSRCDIR.libsecret?=		../../security/libsecret

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.endif	# LIBSECRET_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsecret
