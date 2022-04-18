# $NetBSD: options.mk,v 1.21 2022/04/18 14:59:59 he Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rust
PKG_SUPPORTED_OPTIONS+=	rust-cargo-static rust-docs

.include "../../mk/bsd.fast.prefs.mk"

# The bundled LLVM current has issues building on SunOS.
.if ${OPSYS} != "SunOS"
PKG_SUPPORTED_OPTIONS+=		rust-llvm
# There may be compatibility issues with base LLVM.
.  if !empty(HAVE_LLVM)
PKG_SUGGESTED_OPTIONS+=		rust-llvm
.  endif
.endif

# Bundle OpenSSL and curl into the cargo binary when producing
# bootstraps on NetBSD.
.if ${OPSYS} == "NetBSD" && ${BUILD_TARGET} == "dist"
PKG_SUGGESTED_OPTIONS+=	rust-cargo-static
.endif

# (NetBSD)/sparc64 systems fail to build libunwind 13.0.1,
# and libunwind is depended on here unless rust-llvm is turned
# on.  The latter succeeds, though.  So default to using
# rust-llvm on NetBSD/sparc64.
# Ref. PR#56791
.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc64)
PKG_SUGGESTED_OPTIONS+=		rust-llvm
.endif

.include "../../mk/bsd.options.mk"

#
# Use the internal copy of LLVM or the external one?
# The internal one contains some extra optimizations.
#
.if empty(PKG_OPTIONS:Mrust-llvm)
BUILDLINK_API_DEPENDS.llvm+=	llvm>=12.0.0
.include "../../lang/libunwind/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-llvm-link-shared
#CONFIGURE_ARGS+=	--llvm-libunwind=system
CONFIGURE_ARGS+=	--llvm-root=${BUILDLINK_PREFIX.llvm}
.endif

#
# Link cargo statically against "native" libraries.
# (openssl and curl specifically).
#
.if !empty(PKG_OPTIONS:Mrust-cargo-static)
CONFIGURE_ARGS+=	--enable-cargo-native-static
.else
BUILDLINK_API_DEPENDS.nghttp2+= nghttp2>=1.41.0
BUILDLINK_API_DEPENDS.curl+= 	curl>=7.67.0
.include "../../www/curl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif

#
# Install documentation.
#
.if !empty(PKG_OPTIONS:Mrust-docs)
CONFIGURE_ARGS+=	--enable-docs
.else
CONFIGURE_ARGS+=	--disable-docs
.endif
