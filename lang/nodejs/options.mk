# $NetBSD: options.mk,v 1.10 2016/06/02 09:57:32 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.node
PKG_SUPPORTED_OPTIONS=	openssl dtrace
PKG_SUGGESTED_OPTIONS=	openssl

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
BUILDLINK_API_DEPENDS.openssl+=	openssl>=1.0.2
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--shared-openssl
_WRAP_EXTRA_ARGS.CXX+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
CWRAPPERS_APPEND.cxx+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
.else
CONFIGURE_ARGS+=	--without-ssl
.endif
