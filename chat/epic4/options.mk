# $NetBSD: options.mk,v 1.1 2015/11/07 21:36:57 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.epic4
PKG_SUPPORTED_OPTIONS+=	perl
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mperl)
USE_TOOLS+=		perl:run
CONFIGURE_ARGS+=	--with-perl
.include "../../lang/perl5/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-perl
.endif
