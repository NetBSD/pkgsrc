# $NetBSD: buildlink3.mk,v 1.17 2005/05/09 05:06:55 jlam Exp $

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

.if !defined(PKG_OPTIONS.openldap)
PKG_OPTIONS.openldap!=							\
	cd ${BUILDLINK_PKGSRCDIR.openldap} &&				\
	${MAKE} show-var ${MAKE_FLAGS} VARNAME=PKG_OPTIONS
MAKE_FLAGS+=		PKG_OPTIONS.openldap=${PKG_OPTIONS.openldap:Q}
.endif
MAKE_VARS+=		PKG_OPTIONS.openldap

.if !empty(PKG_OPTIONS.openldap:Mkerberos) || \
    !empty(PKG_OPTIONS.openldap:Msasl)
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.endif
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
