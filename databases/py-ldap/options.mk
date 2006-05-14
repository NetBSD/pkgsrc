# $NetBSD: options.mk,v 1.1 2006/05/14 21:09:20 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-ldap
PKG_SUPPORTED_OPTIONS=	sasl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
PY_LDAP_LIBRARY_DIRS+=	${BUILDLINK_PREFIX.cyrus-sasl}/lib
PY_LDAP_INCLUDE_DIRS+=	${BUILDLINK_PREFIX.cyrus-sasl}/include/sasl
PY_LDAP_LIBS+=		sasl2
.endif
