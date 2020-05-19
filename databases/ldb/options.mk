# $NetBSD: options.mk,v 1.3 2020/05/19 00:21:01 gutteridge Exp $

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
CFG_CACHE=	${WRKSRC}/bin/c4che/default_cache.py
post-configure:
	${MV} ${CFG_CACHE} ${CFG_CACHE}.orig
	${SED} -E -e 's/(ENABLE_LDAP_BACKEND =) True/\1 False/g' \
		${CFG_CACHE}.orig > ${CFG_CACHE}
.endif
