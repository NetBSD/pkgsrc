# $NetBSD: options.mk,v 1.7 2026/04/01 23:19:24 js Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.objfw
.if ${OPSYS} != "Darwin" && \
	${MACHINE_ARCH} != "alpha" && \
	${MACHINE_ARCH} != "coldfire" && \
	${MACHINE_ARCH} != "hppa" && \
	${MACHINE_ARCH} != "ia64" && \
	${MACHINE_ARCH} != "m68k" && \
	${MACHINE_ARCH} != "m68ksf" && \
	${MACHINE_ARCH} != "or1k" && \
	${MACHINE_ARCH} != "sh3eb" && \
	${MACHINE_ARCH} != "sh3el" && \
	${MACHINE_ARCH} != "vax"
# Always use the system compiler on Darwin, as that has the best ObjC support.
# Clang is not available on the architectures listed above.
PKG_SUPPORTED_OPTIONS=		clang
PKG_SUGGESTED_OPTIONS+=		clang
.endif
PKG_OPTIONS_OPTIONAL_GROUPS=	tls
PKG_OPTIONS_GROUP.tls=		openssl gnutls mbedtls mbedtls3 mbedtls4
PKG_SUGGESTED_OPTIONS+=		openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mclang)
CONFIGURE_ARGS+=	OBJC=clang
TOOL_DEPENDS+=		clang>=3.2:../../lang/clang
PKGSRC_COMPILER=	clang
.else
.  if ${OPSYS} != "Darwin"
# Need to explicitly set GCC, as configure prefers Clang.
CONFIGURE_ARGS+=	OBJC=gcc
.  endif
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tls=openssl
PLIST_SRC+=		PLIST.tls
.  if ${OPSYS} == "Darwin"
PLIST_SRC+=		PLIST.tlsframework
.  endif
.elif !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tls=gnutls
USE_TOOLS+=		pkg-config
PLIST_SRC+=		PLIST.tls
.  if ${OPSYS} == "Darwin"
PLIST_SRC+=		PLIST.tlsframework
.  endif
.elif !empty(PKG_OPTIONS:Msecuretransport)
CONFIGURE_ARGS+=	--with-tls=securetransport
PLIST_SRC+=		PLIST.tls
.  if ${OPSYS} == "Darwin"
PLIST_SRC+=		PLIST.tlsframework
.  endif
.elif !empty(PKG_OPTIONS:Mmbedtls)
.  include "../../security/mbedtls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tls=mbedtls
PLIST_SRC+=		PLIST.tls
.  if ${OPSYS} == "Darwin"
PLIST_SRC+=		PLIST.tlsframework
.  endif
.elif !empty(PKG_OPTIONS:Mmbedtls3)
.  include "../../security/mbedtls3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tls=mbedtls
PLIST_SRC+=		PLIST.tls
.  if ${OPSYS} == "Darwin"
PLIST_SRC+=		PLIST.tlsframework
.  endif
.elif !empty(PKG_OPTIONS:Mmbedtls4)
.  include "../../security/mbedtls4/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tls=mbedtls
PLIST_SRC+=		PLIST.tls
.  if ${OPSYS} == "Darwin"
PLIST_SRC+=		PLIST.tlsframework
.  endif
.else
CONFIGURE_ARGS+=	--without-tls
.endif
