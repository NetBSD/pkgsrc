# $NetBSD: options.mk,v 1.8 2024/09/11 13:29:14 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgresql16
PKG_SUPPORTED_OPTIONS=	bonjour dtrace icu llvm gssapi ldap nls pam lz4
PKG_SUGGESTED_OPTIONS=	icu nls lz4

# XXX This should use ${KRB5_TYPE}, not ${KRB5_DEFAULT:U}.  But
# bsd.prefs.mk isn't guaranteed to define either KRB5_TYPE or
# KRB5_DEFAULT -- the default value isn't provided by
# mk/defaults/mk.conf; it's provided by krb5.buildlink3.mk, which pulls
# in krb5 as a dependency, so we can't include it unless the option is
# enabled.
#
# To break this cycle, we assume nothing uses mit-krb5 by default, and
# only enable the gssapi option by default if the user or platform has
# explicitly requested mit-krb5 by setting KRB5_DEFAULT.  (This is
# currently true: krb5.buildlink3.mk rev. 1.14 picks heimdal as the
# default.)
#
# See below about why this is conditional on mit-krb5.
PKG_SUGGESTED_OPTIONS+=	${"${KRB5_DEFAULT:U}" == "mit-krb5":?gssapi:}

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

# GSSAPI (Kerberos5) authentication for the PostgreSQL backend
.if !empty(PKG_OPTIONS:Mgssapi)
# Currently no released version of heimdal supports
# gss_store_cred_into:
# https://github.com/heimdal/heimdal/issues/1258
# But pgsql requires it now:
# https://www.postgresql.org/message-id/flat/abcc73d0-acf7-6896-e0dc-f5bc12a61bb1%40postgresql.org
# So we require mit-krb5 until something changes with either pgsql or
# heimdal.
KRB5_ACCEPTED=		mit-krb5
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

.if !empty(PKG_OPTIONS:Micu)
.  include "../../textproc/icu/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-icu
.endif
