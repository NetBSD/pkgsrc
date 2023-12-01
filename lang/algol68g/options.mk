# $NetBSD: options.mk,v 1.4 2023/12/01 18:35:11 rhialto Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.a68g
PKG_SUPPORTED_OPTIONS=	plotutils pgsql longtypes
PKG_SUGGESTED_OPTIONS=	plotutils

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mplotutils)
.  include "../../graphics/plotutils/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-plotutils
.else
CONFIGURE_ARGS+=	--disable-plotutils
.endif

# The implementation of this is somewhat Linux-centric so
# it may not fully work as expected when enabled elsewhere.
.if !empty(PKG_OPTIONS:Mlongtypes)
.  include "../../math/mpfr/buildlink3.mk" # fails some configure checks
.  include "../../math/libquadmath/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-long-types
.else
CONFIGURE_ARGS+=	--disable-long-types
.endif

# It seems that when including PostgreSQL support it doesn't actually
# need to have it installed at build time, just at run time.
# So maybe this DEPENDS is undesirable.
.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--enable-postgresql
.  include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-postgresql
.endif
