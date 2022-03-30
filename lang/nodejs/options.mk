# $NetBSD: options.mk,v 1.14 2022/03/30 06:52:33 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nodejs
PKG_SUPPORTED_OPTIONS=	openssl dtrace
PKG_SUGGESTED_OPTIONS=	openssl

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "SunOS" || ${OPSYS} == "Darwin") \
    && exists(/usr/sbin/dtrace)
PKG_SUGGESTED_OPTIONS+=	dtrace
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dtrace

.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=	--with-dtrace
PLIST.dtrace=		yes
.else
CONFIGURE_ARGS+=	--without-dtrace
.endif

# print-PLIST helper
PRINT_PLIST_AWK+=	{if ($$0 ~ /lib\/dtrace/) {$$0 = "$${PLIST.dtrace}" $$0;}}

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--shared-openssl
_WRAP_EXTRA_ARGS.CXX+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
CWRAPPERS_APPEND.cxx+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
.else
CONFIGURE_ARGS+=	--without-ssl
.endif
