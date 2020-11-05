# $NetBSD: options.mk,v 1.1 2020/11/05 16:31:45 bacon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openblas
# Auto-detect CPU features at runtime or use static features from build host
PKG_SUPPORTED_OPTIONS=	dynamic-arch
PKG_SUGGESTED_OPTIONS=	dynamic-arch

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdynamic-arch)
MAKE_FLAGS+=	DYNAMIC_ARCH=1
.else
MAKE_FLAGS+=	DYNAMIC_ARCH=0
.endif

# Other options create variants of the library, not configurations of one.
# Especially INTERFACE64, which changes the API!
