# $NetBSD: buildlink3.mk,v 1.14 2012/12/16 01:36:44 obache Exp $

BUILDLINK_TREE+=	cyrus-sasl

.if !defined(CYRUS_SASL_BUILDLINK3_MK)
CYRUS_SASL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cyrus-sasl+=	cyrus-sasl>=2.1.12
BUILDLINK_ABI_DEPENDS.cyrus-sasl+=	cyrus-sasl>=2.1.26
BUILDLINK_PKGSRCDIR.cyrus-sasl?=	../../security/cyrus-sasl

# Cyrus SASL mechanisms are shared modules loaded via dlopen().
.include "../../mk/dlopen.buildlink3.mk"
.endif # CYRUS_SASL_BUILDLINK3_MK

BUILDLINK_TREE+=	-cyrus-sasl
