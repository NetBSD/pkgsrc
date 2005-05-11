# $NetBSD: buildlink3.mk,v 1.20 2005/05/11 22:08:18 jlam Exp $

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
BUILDLINK_RECOMMENDED.openldap+=	openldap>=2.2.18nb1
BUILDLINK_PKGSRCDIR.openldap?=		../../databases/openldap
.endif	# OPENLDAP_BUILDLINK3_MK

.if !defined(PKG_BUILD_OPTIONS.openldap)
PKG_BUILD_OPTIONS.openldap!=						\
	cd ${BUILDLINK_PKGSRCDIR.openldap} &&				\
	${MAKE} show-var ${MAKEFLAGS} VARNAME=PKG_OPTIONS
MAKEFLAGS+=	PKG_BUILD_OPTIONS.openldap=${PKG_BUILD_OPTIONS.openldap:Q}
.endif
MAKEVARS+=	PKG_BUILD_OPTIONS.openldap

.if !empty(PKG_BUILD_OPTIONS.openldap:Mkerberos) || \
    !empty(PKG_BUILD_OPTIONS.openldap:Msasl)
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.endif
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
