# $NetBSD: options.mk,v 1.4 2022/08/09 12:08:28 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgresql14
PKG_SUPPORTED_OPTIONS=	bonjour dtrace icu llvm gssapi ldap nls pam lz4
PKG_SUGGESTED_OPTIONS=	gssapi nls lz4

PLIST_VARS+=		gssapi llvm nls

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
PLIST.gssapi=		yes
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
.if !empty(PKG_OPTIONS:Mllvm)
.  include "../../lang/llvm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-llvm
CONFIGURE_ENV+=		CLANG=${CC}	# XXX: make it be better
PLIST.llvm=		yes
.endif

# lz4 support
.if !empty(PKG_OPTIONS:Mlz4)
.  include "../../archivers/lz4/buildlink3.mk"
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--with-lz4
.endif

# NLS support
.if !empty(PKG_OPTIONS:Mnls)
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST.nls=		yes
BROKEN_GETTEXT_DETECTION=	yes
.  include "../../devel/gettext-lib/buildlink3.mk"
.  if !empty(USE_BUILTIN.gettext:M[nN][oO])
CPPFLAGS+=		-I${PREFIX}/include/gettext
.  endif
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

# PAM authentication for the PostgreSQL backend
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif
