# $NetBSD: buildlink3.mk,v 1.2 2025/12/13 12:41:21 wiz Exp $

BUILDLINK_TREE+=	flowerysong-openarc

.if !defined(FLOWERYSONG_OPENARC_BUILDLINK3_MK)
FLOWERYSONG_OPENARC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flowerysong-openarc+=	flowerysong-openarc>=1.3.0
BUILDLINK_PKGSRCDIR.flowerysong-openarc?=	../../mail/flowerysong-openarc

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.endif	# FLOWERYSONG_OPENARC_BUILDLINK3_MK

BUILDLINK_TREE+=	-flowerysong-openarc
