# $NetBSD: buildlink3.mk,v 1.13 2004/11/08 12:17:50 markd Exp $

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

.if !empty(PKG_OPTIONS.openldap:Mkerberos)
.  if empty(PKG_OPTIONS.openldap:Msasl)
PKG_OPTIONS.openldap+=	sasl
.  endif
.endif

.if !empty(PKG_OPTIONS.openldap:Msasl)
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS.openldap:Mslp)
.  include "../../net/openslp/buildlink3.mk"
.endif
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
