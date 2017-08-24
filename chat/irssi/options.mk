# $NetBSD: options.mk,v 1.18 2017/08/24 14:05:21 khorben Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.irssi
PKG_SUPPORTED_OPTIONS=		ssl perl truecolor
PKG_SUGGESTED_OPTIONS=		ssl perl truecolor

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mperl)
USE_TOOLS+=		perl:run
PERL5_PACKLIST=		auto/Irssi/.packlist
PERL5_PACKLIST+=	auto/Irssi/Irc/.packlist
PERL5_PACKLIST+=	auto/Irssi/UI/.packlist
PERL5_PACKLIST+=	auto/Irssi/TextUI/.packlist
.include "../../lang/perl5/packlist.mk"
.include "../../lang/perl5/buildlink3.mk"
# actually we don't need --with-perl here, irssi is compiled with it by default
# but who knows what may happen in future versions
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--with-perl-lib=vendor
.else
CONFIGURE_ARGS+=	--with-perl=no
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if !empty(PKG_OPTIONS:Mtruecolor)
CONFIGURE_ARGS+=	--enable-true-color
.endif
