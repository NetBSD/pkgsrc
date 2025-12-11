# $NetBSD: buildlink3.mk,v 1.1 2025/12/11 00:48:27 manu Exp $

BUILDLINK_TREE+=	openarc

.if !defined(OPENARC_BUILDLINK3_MK)
OPENARC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openarc+=	openarc>=1.1.3nb2
BUILDLINK_ABI_DEPENDS.openarc?=	openarc>=20180921nb2
BUILDLINK_PKGSRCDIR.openarc?=	../../mail/openarc

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.endif	# OPENARC_BUILDLINK3_MK

BUILDLINK_TREE+=	-openarc
