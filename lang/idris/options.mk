# $NetBSD: options.mk,v 1.1 2020/01/20 23:32:38 pho Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.idris
PKG_SUPPORTED_OPTIONS=		idris-ffi gmp
PKG_SUGGESTED_OPTIONS=		idris-ffi gmp

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

###
### Build support for libffi
###
.if !empty(PKG_OPTIONS:Midris-ffi)
CONFIGURE_ARGS+=	-f ffi
.  include "../../devel/hs-libffi/buildlink3.mk"
.endif

###
### Use GMP for Integers
###
.if !empty(PKG_OPTIONS:Mgmp)
CONFIGURE_ARGS+=	-f gmp
.  include "../../devel/gmp/buildlink3.mk"
.  include "../../devel/hs-libffi/buildlink3.mk"
.endif
