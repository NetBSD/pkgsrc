# $NetBSD: buildlink3.mk,v 1.12 2004/10/03 00:13:22 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OPENLDAP_BUILDLINK3_MK:=	${OPENLDAP_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openldap
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopenldap}
BUILDLINK_PACKAGES+=	openldap

.if !empty(OPENLDAP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.openldap+=		openldap>=2.1.22
BUILDLINK_RECOMMENDED.openldap+=	openldap>=2.2.13nb2
BUILDLINK_PKGSRCDIR.openldap?=		../../databases/openldap
.endif	# OPENLDAP_BUILDLINK3_MK

PKG_OPTIONS.openldap?=	${PKG_DEFAULT_OPTIONS}

.if !empty(PKG_OPTIONS.openldap:Msasl)
.  if !defined(USE_SASL2) && !defined(USE_SASL)
.    include "../../security/cyrus-sasl2/buildlink3.mk"
.  elif defined(USE_SASL2) && !empty(USE_SASL2:M[yY][eE][sS])
.    include "../../security/cyrus-sasl2/buildlink3.mk"
.  elif defined(USE_SASL) && !empty(USE_SASL:M[yY][eE][sS])
.    include "../../security/cyrus-sasl/buildlink3.mk"
.  endif
.endif
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
