# $NetBSD: buildlink3.mk,v 1.6 2005/01/14 05:15:39 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CYRUS_SASL_BUILDLINK3_MK:=	${CYRUS_SASL_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cyrus-sasl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncyrus-sasl}
BUILDLINK_PACKAGES+=	cyrus-sasl

.if !empty(CYRUS_SASL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.cyrus-sasl+=		cyrus-sasl>=1.5.27nb3
BUILDLINK_RECOMMENDED.cyrus-sasl+=	cyrus-sasl>=1.5.27nb7
BUILDLINK_PKGSRCDIR.cyrus-sasl?=	../../security/cyrus-sasl
.endif	# CYRUS_SASL_BUILDLINK3_MK

PKG_OPTIONS.cyrus-sasl?=	${PKG_DEFAULT_OPTIONS}

.if !empty(PKG_OPTIONS.cyrus-sasl:MPAM)
.  include "../../mk/pam.buildlink3.mk"
.endif

# Cyrus SASL mechanisms are shared modules loaded via dlopen().
.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
