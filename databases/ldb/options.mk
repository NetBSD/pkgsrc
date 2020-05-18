# $NetBSD: options.mk,v 1.2 2020/05/18 15:39:20 hauke Exp $

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
	mv ${CFG_CACHE} ${CFG_CACHE}.orig
	sed -E -e 's/(ENABLE_LDAP_BACKEND =) True/\1 False/g' \
		${CFG_CACHE}.orig > ${CFG_CACHE}
.endif
