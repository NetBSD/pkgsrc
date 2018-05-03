# $NetBSD: options.mk,v 1.11 2018/05/03 21:19:16 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.node
PKG_SUPPORTED_OPTIONS=	openssl dtrace
PKG_SUGGESTED_OPTIONS=	openssl

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "SunOS" || ${OPSYS} == "Darwin") \
    && exists(/usr/sbin/dtrace)
PKG_SUGGESTED_OPTIONS+=	dtrace
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dtrace openssl

.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=	--with-dtrace
PLIST.dtrace=		yes
.else
CONFIGURE_ARGS+=	--without-dtrace
.endif

# print-PLIST helper
PRINT_PLIST_AWK+=	{if ($$0 ~ /lib\/dtrace/) {$$0 = "$${PLIST.dtrace}" $$0;}}
PRINT_PLIST_AWK+=	{if ($$0 ~ /include\/node\/openssl/) {$$0 = "$${PLIST.openssl}" $$0;}}

.if !empty(PKG_OPTIONS:Mopenssl)
# nodejs 10.x requires OpenSSL 1.1.x. Use embedded source until we have such.
PLIST.openssl=		yes
.else
CONFIGURE_ARGS+=	--without-ssl
.endif
