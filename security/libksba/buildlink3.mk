# $NetBSD: buildlink3.mk,v 1.14 2011/04/22 13:42:47 obache Exp $

BUILDLINK_TREE+=	libksba

.if !defined(LIBKSBA_BUILDLINK3_MK)
LIBKSBA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libksba+=	libksba>=0.9.7
BUILDLINK_ABI_DEPENDS.libksba+=	libksba>=1.2.0nb1
BUILDLINK_PKGSRCDIR.libksba?=	../../security/libksba

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.endif # LIBKSBA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libksba
