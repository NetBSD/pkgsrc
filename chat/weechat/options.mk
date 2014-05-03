# $NetBSD: options.mk,v 1.11 2014/05/03 13:27:33 alnsn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.weechat
PKG_SUPPORTED_OPTIONS=	charset gnutls python lua wide-curses perl ruby
PKG_SUGGESTED_OPTIONS=	charset gnutls

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		charset lua plugin python perl ruby

.if !empty(PKG_OPTIONS:Mcharset)
CMAKE_ARGS+=		-DENABLE_CHARSET:BOOL=ON
PLIST.charset=		yes
.else
CMAKE_ARGS+=		-DENABLE_CHARSET:BOOL=OFF
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
CMAKE_ARGS+=		-DENABLE_PYTHON:BOOL=ON
PLIST.python=		yes
.else
CMAKE_ARGS+=		-DENABLE_PYTHON:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_INCOMPATIBLE=	52
.include "../../lang/lua/buildlink3.mk"
CMAKE_ARGS+=		-DENABLE_LUA:BOOL=ON
PLIST.lua=		yes
.else
CMAKE_ARGS+=		-DENABLE_LUA:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mperl)
.include "../../lang/perl5/buildlink3.mk"
CMAKE_ARGS+=		-DENABLE_PERL:BOOL=ON
USE_TOOLS+=		perl
PLIST.perl=		yes
.else
CMAKE_ARGS+=		-DENABLE_PERL:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mruby)
.include "../../lang/ruby/buildlink3.mk"
CMAKE_ARGS+=		-DENABLE_RUBY:BOOL=ON
USE_TOOLS+=		ruby
PLIST.ruby=		yes
.else
CMAKE_ARGS+=		-DENABLE_RUBY:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mpython) || \
    !empty(PKG_OPTIONS:Mlua) || \
    !empty(PKG_OPTIONS:Mcharset)
PLIST.plugin=		yes
.endif
