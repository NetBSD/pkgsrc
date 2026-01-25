# $NetBSD: buildlink3.mk,v 1.2 2026/01/25 00:59:15 gutteridge Exp $

BUILDLINK_TREE+=	libewf

.if !defined(LIBEWF_BUILDLINK3_MK)
LIBEWF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libewf+=	libewf>=20150126
BUILDLINK_PKGSRCDIR.libewf?=	../../devel/libewf

BUILDLINK_API_DEPENDS.openssl+= openssl>=3.0
.include "../../security/openssl/buildlink3.mk"

.endif	# LIBEWF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libewf
