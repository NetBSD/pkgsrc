# $NetBSD: buildlink3.mk,v 1.3 2012/12/16 01:52:33 obache Exp $

BUILDLINK_TREE+=	liboauth

.if !defined(LIBOAUTH_BUILDLINK3_MK)
LIBOAUTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboauth+=	liboauth>=0.8.9
BUILDLINK_ABI_DEPENDS.liboauth?=	liboauth>=0.9.4nb1
BUILDLINK_PKGSRCDIR.liboauth?=	../../security/liboauth

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# LIBOAUTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboauth
