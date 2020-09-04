# $NetBSD: options.mk,v 1.5 2020/09/04 11:43:05 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.oinkmaster

PKG_SUPPORTED_OPTIONS=		perl
PKG_OPTIONS_LEGACY_OPTS+=	oinkmaster-perl-tools:perl

.include "../../mk/bsd.options.mk"

###
### Use perl tools for downloading rule files
###
.if !empty(PKG_OPTIONS:Mperl)
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
.else
DEPENDS+=	wget>=1.00:../../net/wget
.endif
