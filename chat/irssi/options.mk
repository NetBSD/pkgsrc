# $NetBSD: options.mk,v 1.6 2007/11/25 13:19:04 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.irssi
PKG_SUPPORTED_OPTIONS=	inet6 irssi-perl ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mirssi-perl)
USE_TOOLS+=		perl
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

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
