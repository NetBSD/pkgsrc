# $NetBSD: options.mk,v 1.3 2020/05/21 07:02:56 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.a68g
PKG_SUPPORTED_OPTIONS=	plotutils pgsql
PKG_SUGGESTED_OPTIONS=	plotutils

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mplotutils)
.  include "../../graphics/plotutils/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-plotutils
.else
CONFIGURE_ARGS+=	--disable-plotutils
.endif

# It seems that when including PostgreSQL support it doesn't actually
# need to have it installed at build time, just at run time.
# So maybe this DEPENDS is undesirable.
.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--enable-postgresql
.include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-postgresql
.endif
