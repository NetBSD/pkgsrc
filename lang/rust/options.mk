# $NetBSD: options.mk,v 1.26 2022/07/11 20:13:50 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rust
PKG_SUPPORTED_OPTIONS+=	rust-cargo-static rust-docs

.include "../../mk/bsd.fast.prefs.mk"

# The bundled LLVM current has issues building on SunOS.
.if ${OPSYS} != "SunOS"
PKG_SUPPORTED_OPTIONS+=		rust-internal-llvm
# There may be compatibility issues with the base LLVM on e.g. NetBSD.
.  if !empty(HAVE_LLVM) || !empty(MACHINE_PLATFORM:MDarwin-*-aarch64)
PKG_SUGGESTED_OPTIONS+=		rust-internal-llvm
.  endif
.endif

# Bundle OpenSSL and curl into the cargo binary when producing
# bootstraps on NetBSD.
.if ${OPSYS} == "NetBSD" && ${BUILD_TARGET} == "dist"
PKG_SUGGESTED_OPTIONS+=	rust-cargo-static
.endif

PKG_OPTIONS_LEGACY_OPTS+=	rust-llvm:rust-internal-llvm

.include "../../mk/bsd.options.mk"

#
# Use the internal copy of LLVM or the external one?
#
.if empty(PKG_OPTIONS:Mrust-internal-llvm)
BUILDLINK_API_DEPENDS.llvm+=	llvm>=12.0.0
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
