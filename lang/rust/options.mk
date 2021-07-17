# $NetBSD: options.mk,v 1.16 2021/07/17 13:16:38 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rust
PKG_SUPPORTED_OPTIONS+=	rust-cargo-static
PKG_SUPPORTED_OPTIONS+=	rust-llvm

.include "../../mk/bsd.fast.prefs.mk"

# There may be compatibility issues with base LLVM.
.if !empty(HAVE_LLVM)
PKG_SUGGESTED_OPTIONS+=	rust-llvm
.endif

# macOS/arm64 currently cannot used shared llvm
.if !empty(MACHINE_PLATFORM:MDarwin-*-aarch64)
PKG_SUGGESTED_OPTIONS+=	rust-llvm
.endif

# Bundle OpenSSL and curl into the cargo binary when producing
# bootstraps on NetBSD.
.if ${OPSYS} == "NetBSD" && ${BUILD_TARGET} == "dist"
PKG_SUGGESTED_OPTIONS+=	rust-cargo-static
.endif

.include "../../mk/bsd.options.mk"

#
# Use the internal copy of LLVM.
# This contains some extra optimizations.
#
.if empty(PKG_OPTIONS:Mrust-llvm)
.include "../../lang/llvm/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-llvm-link-shared
CONFIGURE_ARGS+=	--llvm-root=${BUILDLINK_PREFIX.llvm}
# XXX: fix for Rust 1.41.0 https://github.com/rust-lang/rust/issues/68714
MAKE_ENV+=	LIBRARY_PATH=${BUILDLINK_PREFIX.llvm}/lib
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
