# $NetBSD: buildlink3.mk,v 1.3 2023/10/24 22:08:25 wiz Exp $

BUILDLINK_TREE+=	srtp

.if !defined(SRTP_BUILDLINK3_MK)
SRTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.srtp+=	srtp>=2.3.0
BUILDLINK_ABI_DEPENDS.srtp?=	srtp>=2.5.0nb1
BUILDLINK_PKGSRCDIR.srtp?=	../../comms/srtp
.include "../../security/openssl/buildlink3.mk"
.endif	# SRTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-srtp
