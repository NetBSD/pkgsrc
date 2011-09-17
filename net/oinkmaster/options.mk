# $NetBSD: options.mk,v 1.2 2011/09/17 11:12:26 shattered Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.oinkmaster

PKG_SUPPORTED_OPTIONS=	perl
PKG_OPTIONS_LEGACY_OPTS+=	oinkmaster-perl-tools:perl

.include "../../mk/bsd.options.mk"

###
### Use perl tools for downloading rule files
###
.if !empty(PKG_OPTIONS:Mperl)
DEPENDS+=	p5-Archive-Tar-[0-9]*:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-IO-Zlib-[0-9]*:../../devel/p5-IO-Zlib
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
.else
DEPENDS+=	wget>=1.00:../../net/wget
.endif
