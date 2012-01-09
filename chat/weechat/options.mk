# $NetBSD: options.mk,v 1.8 2012/01/09 14:53:31 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.weechat
PKG_SUPPORTED_OPTIONS=	charset gnutls python lua wide-curses perl ruby
PKG_SUGGESTED_OPTIONS=	charset

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		charset lua plugin python perl ruby

.if !empty(PKG_OPTIONS:Mcharset)
CONFIGURE_ARGS+=	--enable-charset
PLIST.charset=		yes
.else
CONFIGURE_ARGS+=	--disable-charset
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwide-curses)
.include "../../devel/ncursesw/buildlink3.mk"
.else
.include "../../devel/ncurses/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/extension.mk"
CONFIGURE_ARGS+=	--enable-python
PLIST.python=		yes
.else
CONFIGURE_ARGS+=	--disable-python
.endif

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-lua
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

.if !empty(PKG_OPTIONS:Mperl)
.include "../../lang/perl5/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-perl
USE_TOOLS+=		perl
PLIST.perl=		yes
.else
CONFIGURE_ARGS+=	--disable-perl
.endif

.if !empty(PKG_OPTIONS:Mruby)
.include "../../lang/ruby/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ruby
USE_TOOLS+=		ruby
PLIST.ruby=		yes
.else
CONFIGURE_ARGS+=	--disable-ruby
.endif

.if !empty(PKG_OPTIONS:Mpython) || \
    !empty(PKG_OPTIONS:Mlua) || \
    !empty(PKG_OPTIONS:Mcharset)
PLIST.plugin=		yes
.endif
