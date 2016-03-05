# $NetBSD: buildlink3.mk,v 1.2 2016/03/05 11:27:50 jperkin Exp $

BUILDLINK_TREE+=	opendmarc

.if !defined(OPENDMARC_BUILDLINK3_MK)
OPENDMARC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opendmarc+=	opendmarc>=1.1.3nb2
BUILDLINK_ABI_DEPENDS.opendmarc?=	opendmarc>=1.3.1nb2
BUILDLINK_PKGSRCDIR.opendmarc?=	../../mail/opendmarc

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.endif	# OPENDMARC_BUILDLINK3_MK

BUILDLINK_TREE+=	-opendmarc
