# $NetBSD: buildlink3.mk,v 1.3 2006/07/08 23:10:40 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
OPENLDAP_BUILDLINK3_MK:=		${OPENLDAP_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=			openldap-client
.endif

BUILDLINK_PACKAGES:=			${BUILDLINK_PACKAGES:Nopenldap-client}
BUILDLINK_PACKAGES+=			openldap-client
BUILDLINK_ORDER:=			${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}openldap-client

.if !empty(OPENLDAP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.openldap-client+=	openldap-client>=2.3.11nb2
BUILDLINK_PKGSRCDIR.openldap-client?=	../../databases/openldap-client

# Export the deprecated API from the openldap-2.2.x releases.
BUILDLINK_CPPFLAGS.openldap-client+=	-DLDAP_DEPRECATED
.endif	# OPENLDAP_BUILDLINK3_MK

.if !defined(PKG_BUILD_OPTIONS.openldap-client)
PKG_BUILD_OPTIONS.openldap-client!=					\
	cd ${BUILDLINK_PKGSRCDIR.openldap-client} &&			\
	${MAKE} show-var ${MAKEFLAGS} VARNAME=PKG_OPTIONS
MAKEFLAGS+=	PKG_BUILD_OPTIONS.openldap-client=${PKG_BUILD_OPTIONS.openldap-client:Q}
.endif
MAKEVARS+=	PKG_BUILD_OPTIONS.openldap-client

.if !empty(PKG_BUILD_OPTIONS.openldap-client:Mkerberos) || \
    !empty(PKG_BUILD_OPTIONS.openldap-client:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
.endif
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
