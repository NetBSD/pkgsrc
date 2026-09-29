# $NetBSD: buildlink3.mk,v 1.11 2026/09/29 06:07:23 wiz Exp $

BUILDLINK_TREE+=	libsecret

.if !defined(LIBSECRET_BUILDLINK3_MK)
LIBSECRET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsecret+=	libsecret>=0.12
BUILDLINK_ABI_DEPENDS.libsecret+=	libsecret>=0.20.5nb6
BUILDLINK_PKGSRCDIR.libsecret?=		../../security/libsecret

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.endif	# LIBSECRET_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsecret
