# $NetBSD: options.mk,v 1.4 2021/05/11 10:57:34 hauke Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ldb
PKG_SUPPORTED_OPTIONS=	ldap
PKG_SUGGESTED_OPTIONS=	ldap

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		ldap

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
PLIST.ldap=		yes
.else
# No official way to configure without ldap
WSCRIPT=	${WRKSRC}/wscript
pre-configure:
	${MV} ${WSCRIPT} ${WSCRIPT}.old
	${SED} -E -e 's/(ENABLE_LDAP_BACKEND =) True/\1 False/g' \
		${WSCRIPT}.old > ${WSCRIPT}
.endif
