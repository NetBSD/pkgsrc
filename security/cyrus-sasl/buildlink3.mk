# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 22:39:36 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CYRUS_SASL_BUILDLINK3_MK:=	${CYRUS_SASL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cyrus-sasl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncyrus-sasl}
BUILDLINK_PACKAGES+=	cyrus-sasl
BUILDLINK_ORDER+=	cyrus-sasl

.if !empty(CYRUS_SASL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.cyrus-sasl+=	cyrus-sasl>=2.1.12
BUILDLINK_ABI_DEPENDS.cyrus-sasl?=	cyrus-sasl>=2.1.20nb3
BUILDLINK_PKGSRCDIR.cyrus-sasl?=	../../security/cyrus-sasl
.endif	# CYRUS_SASL_BUILDLINK3_MK

# Cyrus SASL mechanisms are shared modules loaded via dlopen().
.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
