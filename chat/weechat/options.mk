# $NetBSD: options.mk,v 1.24 2020/03/30 11:07:18 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.weechat
# mk/curses will handle wide-curses
PKG_SUPPORTED_OPTIONS=	gnutls python lua wide-curses perl ruby
PKG_SUGGESTED_OPTIONS=	gnutls python lua wide-curses perl ruby

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.fast.prefs.mk"

PLIST_VARS+=		lua plugin python perl ruby

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpython)
PYTHON_VERSIONS_INCOMPATIBLE=	27
.include "../../lang/python/extension.mk"
CMAKE_ARGS+=	-DENABLE_PYTHON=ON
PLIST.python=	yes
.else
CMAKE_ARGS+=	-DENABLE_PYTHON=OFF
.endif

.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_INCOMPATIBLE=	52
.include "../../lang/lua/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_LUA=ON
PLIST.lua=	yes
.else
CMAKE_ARGS+=	-DENABLE_LUA=OFF
.endif

.if !empty(PKG_OPTIONS:Mperl)
.include "../../lang/perl5/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_PERL=ON
USE_TOOLS+=	perl
PLIST.perl=	yes
.else
CMAKE_ARGS+=	-DENABLE_PERL=OFF
.endif

.if !empty(PKG_OPTIONS:Mruby)
.include "../../lang/ruby/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_RUBY=ON
CMAKE_ARGS+=	-DRUBY_INCLUDE_DIRS=${PREFIX}/${RUBY_INC}
CMAKE_ARGS+=	-DRUBY_LIB=${PREFIX}/lib/libruby${RUBY_SHLIB}
PLIST.ruby=	yes
#BUILDLINK_INCDIRS.${RUBY_BASE}+=	${RUBY_INC}
#BUILDLINK_INCDIRS.${RUBY_BASE}+=	${RUBY_ARCHINC}
.else
CMAKE_ARGS+=		-DENABLE_RUBY:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mpython) || \
    !empty(PKG_OPTIONS:Mlua)
PLIST.plugin=		yes
.endif
