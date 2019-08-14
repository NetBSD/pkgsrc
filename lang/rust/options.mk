# $NetBSD: options.mk,v 1.3 2019/08/14 16:00:23 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.rust

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
# LLVM uses -std=c++11
GCC_REQD+=	4.8
BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
.include "../../devel/cmake/buildlink3.mk"
.else
.include "../../lang/llvm/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-llvm-link-shared
CONFIGURE_ARGS+=	--llvm-root=${BUILDLINK_PREFIX.llvm}
.endif
