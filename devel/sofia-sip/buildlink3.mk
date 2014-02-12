# $NetBSD: buildlink3.mk,v 1.3 2014/02/12 23:17:51 tron Exp $

BUILDLINK_TREE+=	sofia-sip

.if !defined(SOFIA_SIP_BUILDLINK3_MK)
SOFIA_SIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sofia-sip+=	sofia-sip>=1.12.10
BUILDLINK_ABI_DEPENDS.sofia-sip?=		sofia-sip>=1.12.11nb2
BUILDLINK_PKGSRCDIR.sofia-sip?=		../../devel/sofia-sip

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# SOFIA_SIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-sofia-sip
