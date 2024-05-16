# $NetBSD: options.mk,v 1.23 2024/05/16 23:34:12 riastradh Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.irssi
PKG_SUPPORTED_OPTIONS=		otr perl truecolor
PKG_SUGGESTED_OPTIONS=		otr perl truecolor

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Motr)
# Build it into the main irssi executable instead of a module.
CONFIGURE_ARGS+=	--with-otr=static
.  if ${USE_CROSS_COMPILE:tl} == "yes"
CONFIGURE_ARGS+=	LIBGCRYPT_CONFIG=${CROSS_DESTDIR:Q}${LOCALBASE:Q}/bin/libgcrypt-config
.  endif
.include "../../chat/libotr/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-otr=no
.endif

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
