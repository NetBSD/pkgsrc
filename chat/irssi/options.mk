# $NetBSD: options.mk,v 1.1 2005/05/31 21:58:38 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.irssi
PKG_SUPPORTED_OPTIONS=	inet6 irssi-perl ssl
PKG_OPTIONS_LEGACY_VARS+=	IRSSI_USE_PERL:irssi-perl IRSSI_USE_SSL:ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mirssi-perl)
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Irssi/.packlist
PERL5_PACKLIST+=	${PERL5_SITEARCH}/auto/Irssi/Irc/.packlist
PERL5_PACKLIST+=	${PERL5_SITEARCH}/auto/Irssi/UI/.packlist
PERL5_PACKLIST+=	${PERL5_SITEARCH}/auto/Irssi/TextUI/.packlist
.include "../../lang/perl5/buildlink3.mk"
# actually we don't need --with-perl here, irssi is compiled with it by default
# but who knows what may happen in future versions
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--with-perl-lib=site
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
