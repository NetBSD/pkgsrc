# $NetBSD: buildlink3.mk,v 1.1 2023/04/21 00:49:56 manu Exp $

BUILDLINK_TREE+=	openarc

.if !defined(OPENARC_BUILDLINK3_MK)
OPENARC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openarc+=	openarc>=1.1.3nb2
BUILDLINK_ABI_DEPENDS.openarc?=	openarc>=1.3.1nb6
BUILDLINK_PKGSRCDIR.openarc?=	../../mail/openarc

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.endif	# OPENARC_BUILDLINK3_MK

BUILDLINK_TREE+=	-openarc
