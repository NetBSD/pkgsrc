# $NetBSD: buildlink3.mk,v 1.5 2020/03/08 16:48:08 wiz Exp $

BUILDLINK_TREE+=	libsecret

.if !defined(LIBSECRET_BUILDLINK3_MK)
LIBSECRET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsecret+=	libsecret>=0.12
BUILDLINK_ABI_DEPENDS.libsecret?=	libsecret>=0.20.1nb1
BUILDLINK_PKGSRCDIR.libsecret?=		../../security/libsecret

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.endif	# LIBSECRET_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsecret
