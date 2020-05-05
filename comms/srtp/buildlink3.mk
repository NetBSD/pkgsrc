# $NetBSD: buildlink3.mk,v 1.2 2020/05/05 17:54:39 adam Exp $

BUILDLINK_TREE+=	srtp

.if !defined(SRTP_BUILDLINK3_MK)
SRTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.srtp+=	srtp>=2.3.0
BUILDLINK_PKGSRCDIR.srtp?=	../../comms/srtp
.include "../../security/openssl/buildlink3.mk"
.endif	# SRTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-srtp
