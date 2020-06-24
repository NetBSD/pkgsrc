# $NetBSD: options.mk,v 1.7 2020/06/24 09:46:26 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rust
PKG_SUPPORTED_OPTIONS=	# empty

.include "../../mk/bsd.fast.prefs.mk"

# The bundled LLVM current has issues building on SunOS.
.if ${OPSYS} != "SunOS" && ${OPSYS} != "Darwin"
PKG_SUPPORTED_OPTIONS+=		rust-llvm
# There may be compatibility issues with base LLVM.
.  if !empty(HAVE_LLVM)
PKG_SUGGESTED_OPTIONS+=		rust-llvm
.  endif
.endif

.include "../../mk/bsd.options.mk"

#
# Use the internal copy of LLVM.
# This contains some extra optimizations.
#
.if !empty(PKG_OPTIONS:Mrust-llvm)
BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
.include "../../devel/cmake/buildlink3.mk"
.else
.include "../../lang/llvm/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-llvm-link-shared
CONFIGURE_ARGS+=	--llvm-root=${BUILDLINK_PREFIX.llvm}
# XXX: fix for Rust 1.41.0 https://github.com/rust-lang/rust/issues/68714
MAKE_ENV+=	LIBRARY_PATH=${BUILDLINK_PREFIX.llvm}/lib
.endif
