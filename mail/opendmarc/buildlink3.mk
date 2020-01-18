# $NetBSD: buildlink3.mk,v 1.4 2020/01/18 21:48:16 jperkin Exp $

BUILDLINK_TREE+=	opendmarc

.if !defined(OPENDMARC_BUILDLINK3_MK)
OPENDMARC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opendmarc+=	opendmarc>=1.1.3nb2
BUILDLINK_ABI_DEPENDS.opendmarc?=	opendmarc>=1.3.1nb6
BUILDLINK_PKGSRCDIR.opendmarc?=		../../mail/opendmarc

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.endif	# OPENDMARC_BUILDLINK3_MK

BUILDLINK_TREE+=	-opendmarc
