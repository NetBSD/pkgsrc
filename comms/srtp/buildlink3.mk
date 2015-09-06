# $NetBSD: buildlink3.mk,v 1.1 2015/09/06 14:02:08 joerg Exp $

BUILDLINK_TREE+=	srtp

.if !defined(SRTP_BUILDLINK3_MK)
SRTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.srtp+=	srtp>=1.4.4
BUILDLINK_PKGSRCDIR.srtp?=	../../comms/srtp
.endif	# SRTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-srtp
