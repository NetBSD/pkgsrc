# $NetBSD: buildlink3.mk,v 1.24 2021/04/21 13:24:15 adam Exp $

BUILDLINK_TREE+=	liboauth

.if !defined(LIBOAUTH_BUILDLINK3_MK)
LIBOAUTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboauth+=	liboauth>=0.8.9
BUILDLINK_ABI_DEPENDS.liboauth?=	liboauth>=1.0.3nb19
BUILDLINK_PKGSRCDIR.liboauth?=		../../security/liboauth

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# LIBOAUTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboauth
