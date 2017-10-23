# $NetBSD: options.mk,v 1.1 2017/10/23 20:33:49 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgresql10
PKG_SUPPORTED_OPTIONS=	bonjour dtrace icu ldap pam

.include "../../mk/bsd.options.mk"

# Bonjour support
.if !empty(PKG_OPTIONS:Mbonjour)
CONFIGURE_ARGS+=	--with-bonjour
.  if ${OPSYS} != "Darwin"
LIBS+=			-ldns_sd
.  endif
.  include "../../net/mDNSResponder/buildlink3.mk"
.endif

# Dtrace support
.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=	--enable-dtrace
.endif

# ICU collatium support
.if !empty(PKG_OPTIONS:Micu)
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--with-icu
.  include "../../textproc/icu/buildlink3.mk"
.endif

# LDAP authentication for the PostgreSQL backend
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap
.endif

# PAM authentication for the PostgreSQL backend
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif
