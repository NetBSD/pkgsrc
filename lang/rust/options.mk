# $NetBSD: options.mk,v 1.49 2025/08/25 17:51:11 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rust
PKG_SUPPORTED_OPTIONS+=	rust-cargo-static rust-docs

.include "../../mk/bsd.fast.prefs.mk"

# The bundled LLVM current has issues building on SunOS.
.if ${OPSYS} != "SunOS"
PKG_SUPPORTED_OPTIONS+=		rust-internal-llvm
# There may be compatibility issues with the base LLVM on e.g. NetBSD.
.  if !empty(HAVE_LLVM)
PKG_SUGGESTED_OPTIONS+=		rust-internal-llvm
.  endif
.endif

# If cross-building, always use the internal LLVM
.if !empty(TARGET)
PKG_SUGGESTED_OPTIONS+=		rust-internal-llvm
.endif

PKG_OPTIONS_LEGACY_OPTS+=	rust-llvm:rust-internal-llvm

# Bundle OpenSSL and curl into the cargo binary when producing
# bootstraps on NetBSD.
.if ${OPSYS} == "NetBSD" && ${BUILD_TARGET} == "dist"
PKG_SUGGESTED_OPTIONS+=	rust-cargo-static
.endif

.include "../../mk/bsd.options.mk"

# NetBSD/sparc64 when using the internal LLVM needs
# to not use gcc 10.4 or 10.5 (as found in 10.0_BETA or 10.0), ref.
# https://github.com/rust-lang/rust/issues/117231
# (however, gcc from 9.x produces a working LLVM, go figure).
.if ${MACHINE_PLATFORM:MNetBSD-10.*-sparc64}
.  if !empty(PKG_OPTIONS:Mrust-internal-llvm)
# Require GCC 12 (from pkgsrc) to correctly build the embedded LLVM (18.x).
GCC_REQD+=	12
.  endif
.endif

# Apparently, using pkgsrc LLVM 19.x does not work on
# NetBSD/x86_64 9.x and NetBSD/i386 9.x unless rust is built
# with a newer gcc than the platform-included 7.5.0.  Ref.
# https://gnats.netbsd.org/59435 and
# https://mail-index.netbsd.org/pkgsrc-users/2025/05/20/msg041603.html
# and following discussion.
.if empty(PKG_OPTIONS:Mrust-internal-llvm)
.  if ${MACHINE_PLATFORM:MNetBSD-9.*-x86_64} || \
      ${MACHINE_PLATFORM:MNetBSD-9.*-i386}
GCC_REQD+=	10
.  endif
.endif

# Fix for problem seen during rust-installer run w/rust 1.84.1 on macppc,
# "of course" experienced near the end of the build process:
# assertion "memcmp(mf_ptr(mf) - 1, mf_ptr(mf) - matches[i].dist - 2, matches[i].len) == 0" failed: file "xz-5.2/src/liblzma/lz/lz_encoder_mf.c", line 40, function "lzma_mf_find"
# The above is seen with both in-tree gcc (10.5.0) and gcc12 from pkgsrc.
.if ${MACHINE_PLATFORM:MNetBSD-*-powerpc}
GCC_REQD+=	14
.endif

#
# Use the internal copy of LLVM or the external one?
#
.if empty(PKG_OPTIONS:Mrust-internal-llvm)
BUILDLINK_API_DEPENDS.llvm+=	llvm>=18.0.0
.include "../../lang/libunwind/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-llvm-link-shared
CONFIGURE_ARGS+=	--llvm-libunwind=system
CONFIGURE_ARGS+=	--llvm-root=${BUILDLINK_PREFIX.llvm}
# Also turn off build of the internal LLD, as the external LLVM
# may be older (e.g. 18) than the internal LLD (now 19.x), ref.
# https://github.com/rust-lang/rust/issues/131291
CONFIGURE_ARGS+=	--set rust.lld=false
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
