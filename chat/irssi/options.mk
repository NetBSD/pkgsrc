# $NetBSD: options.mk,v 1.21 2019/02/12 04:43:52 maya Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.irssi
PKG_SUPPORTED_OPTIONS=		perl truecolor
PKG_SUGGESTED_OPTIONS=		perl truecolor

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		perl
.if !empty(PKG_OPTIONS:Mperl)
PLIST.perl=		yes
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

.if !empty(PKG_OPTIONS:Mtruecolor)
CONFIGURE_ARGS+=	--enable-true-color
.endif
