# $NetBSD: buildlink3.mk,v 1.1 2004/01/03 23:06:43 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OPENLDAP_BUILDLINK3_MK:=	${OPENLDAP_BUILDLINK3_MK}+

.if !empty(OPENLDAP_BUILDLINK3_MK:M\+)
.  include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.openldap?=	openldap>=2.1.22
BUILDLINK_PKGSRCDIR.openldap?=	../../databases/openldap
.endif	# OPENLDAP_BUILDLINK3_MK

.if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=	openldap
.endif

.if !empty(OPENLDAP_BUILDLINK3_MK:M\+)
BUILDLINK_PACKAGES+=	openldap

.  if defined(USE_SASL2) && (${USE_SASL2} == "YES")
.    include "../../security/cyrus-sasl2/buildlink3.mk"
.  elif defined(USE_SASL) && (${USE_SASL} == "YES")
.    include "../../security/cyrus-sasl/buildlink3.mk"
.  endif
.  include "../../security/openssl/buildlink3.mk"
.endif	# OPENLDAP_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
