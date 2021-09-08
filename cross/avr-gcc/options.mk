# $NetBSD: options.mk,v 1.1 2021/09/08 12:08:21 micha Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.avr-gcc
PKG_SUPPORTED_OPTIONS=	gcc-inplace-math
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# gcc-inplace-math: Build math libraries in place
.if !empty(PKG_OPTIONS:Mgcc-inplace-math)
.  include "../../devel/gmp/inplace.mk"
.  include "../../math/isl/inplace.mk"
.  include "../../math/mpcomplex/inplace.mk"
.  include "../../math/mpfr/inplace.mk"
.else
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-isl=${BUILDLINK_PREFIX.isl}
CONFIGURE_ARGS+=	--with-mpc=${BUILDLINK_PREFIX.mpcomplex}
CONFIGURE_ARGS+=	--with-mpfr=${BUILDLINK_PREFIX.mpfr}
.  include "../../devel/gmp/buildlink3.mk"
.  include "../../math/isl/buildlink3.mk"
.  include "../../math/mpcomplex/buildlink3.mk"
.  include "../../math/mpfr/buildlink3.mk"
.endif
