# $NetBSD: options.mk,v 1.18 2019/07/09 16:23:04 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.weechat
PKG_SUPPORTED_OPTIONS=	gnutls python lua wide-curses perl ruby
PKG_SUGGESTED_OPTIONS=	gnutls python lua wide-curses perl ruby

.include "../../mk/bsd.options.mk"
# mk/curses will handle wide-curses

PLIST_VARS+=		lua plugin python perl ruby

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/extension.mk"
CMAKE_ARGS+=		-DENABLE_PYTHON:BOOL=ON
CMAKE_ARGS.Darwin+=	-DPYTHON_LIBRARY:FILEPATH=${PREFIX}/lib/libpython${PYVERSSUFFIX}.dylib
CMAKE_ARGS.*+=		-DPYTHON_LIBRARY:FILEPATH=${PREFIX}/lib/libpython${PYVERSSUFFIX}.so
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
CMAKE_ARGS+=		-DRUBY_INCLUDE_DIRS:PATH=${PREFIX}/${RUBY_INC}
CMAKE_ARGS+=		-DRUBY_LIB:FILEPATH=${PREFIX}/lib/libruby${RUBY_SHLIB}
PLIST.ruby=		yes
#BUILDLINK_INCDIRS.${RUBY_BASE}+=	${RUBY_INC}
#BUILDLINK_INCDIRS.${RUBY_BASE}+=	${RUBY_ARCHINC}
.else
CMAKE_ARGS+=		-DENABLE_RUBY:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mpython) || \
    !empty(PKG_OPTIONS:Mlua)
PLIST.plugin=		yes
.endif
