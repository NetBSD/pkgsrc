# $NetBSD: buildlink3.mk,v 1.5 2022/06/28 11:34:23 wiz Exp $

BUILDLINK_TREE+=	opendmarc

.if !defined(OPENDMARC_BUILDLINK3_MK)
OPENDMARC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opendmarc+=	opendmarc>=1.1.3nb2
BUILDLINK_ABI_DEPENDS.opendmarc?=	opendmarc>=1.4.2nb1
BUILDLINK_PKGSRCDIR.opendmarc?=		../../mail/opendmarc

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.endif	# OPENDMARC_BUILDLINK3_MK

BUILDLINK_TREE+=	-opendmarc
