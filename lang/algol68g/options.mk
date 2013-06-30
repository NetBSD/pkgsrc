# $NetBSD: options.mk,v 1.2 2013/06/30 09:43:31 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.a68g
PKG_SUPPORTED_OPTIONS=	plotutils pgsql
PKG_SUGGESTED_OPTIONS=	plotutils

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mplotutils)
.  include "../../graphics/plotutils/buildlink3.mk"
CONFIGURE_ARGS+=	--with-plotutils
.else
CONFIGURE_ARGS+=	--without-plotutils
.endif

# It seems that when including PostgreSQL support it doesn't actually
# need to have it installed at build time, just at run time.
# So maybe this DEPENDS is undesirable.
.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-pgsql
.include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif
