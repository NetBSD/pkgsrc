# $NetBSD: buildlink3.mk,v 1.1 2024/09/13 19:35:15 adam Exp $

BUILDLINK_TREE+=	libjwt

.if !defined(LIBJWT_BUILDLINK3_MK)
LIBJWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libjwt+=	libjwt>=1.17.2
BUILDLINK_PKGSRCDIR.libjwt?=	../../security/libjwt

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.endif	# LIBJWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libjwt
