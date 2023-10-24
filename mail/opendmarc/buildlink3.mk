# $NetBSD: buildlink3.mk,v 1.6 2023/10/24 22:09:48 wiz Exp $

BUILDLINK_TREE+=	opendmarc

.if !defined(OPENDMARC_BUILDLINK3_MK)
OPENDMARC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opendmarc+=	opendmarc>=1.1.3nb2
BUILDLINK_ABI_DEPENDS.opendmarc?=	opendmarc>=1.4.2nb2
BUILDLINK_PKGSRCDIR.opendmarc?=		../../mail/opendmarc

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.endif	# OPENDMARC_BUILDLINK3_MK

BUILDLINK_TREE+=	-opendmarc
