# $NetBSD: options.mk,v 1.1 2018/10/23 16:02:51 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgresql11
PKG_SUPPORTED_OPTIONS=	bonjour dtrace icu llvm gssapi ldap pam
PKG_SUGGESTED_OPTIONS=	gssapi

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

# GSSAPI (Kerberos5) authentication for the PostgreSQL backend
.if !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=       --with-gssapi
.else
CONFIGURE_ARGS+=       --without-gssapi
.endif

# LDAP authentication for the PostgreSQL backend
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap
.endif

# LLVM based JIT support
PLIST_VARS+=		llvm
.if !empty(PKG_OPTIONS:Mllvm)
.  include "../../lang/llvm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-llvm
PLIST.llvm=		yes
.endif

# PAM authentication for the PostgreSQL backend
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif
