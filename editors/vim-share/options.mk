# $NetBSD: options.mk,v 1.9 2020/06/30 18:49:56 nia Exp $

PKG_SUPPORTED_OPTIONS+=	ruby python perl lua luajit
PKG_OPTIONS_VAR=	PKG_OPTIONS.vim

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mruby)
.include "../../lang/ruby/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-rubyinterp
CONFIGURE_ENV+=		vi_cv_path_ruby=${RUBY}
.endif

.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/pyversion.mk"
.  if empty(_PYTHON_VERSION:M3*)
CONFIGURE_ARGS+=	--enable-pythoninterp
CONFIGURE_ARGS+=	--with-python-command=${PYTHONBIN}
.  else
CONFIGURE_ARGS+=	--enable-python3interp
CONFIGURE_ARGS+=	--with-python3-command=${PYTHONBIN}
.  endif
.endif

.if !empty(PKG_OPTIONS:Mperl)
.include "../../lang/perl5/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-perlinterp
CONFIGURE_ENV+=		vi_cv_path_perl=${PERL5:Q}
.endif

.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_ACCEPTED=	53 52 51
.include "../../lang/lua/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-luainterp
CONFIGURE_ARGS+=	--with-lua-prefix=${BUILDLINK_PREFIX.lua}
CONFIGURE_ENV+=		vi_cv_path_plain_lua=${LUA_INTERPRETER}
# pkgsrc has include/lua-5.x instead of include/lua5.x
SUBST_CLASSES+=		lua
SUBST_FILES.lua=	auto/configure
SUBST_STAGE.lua=	pre-configure
SUBST_SED.lua=		-e "s,include/lua,include/lua-,g"
.endif

.if !empty(PKG_OPTIONS:Mluajit)
.include "../../lang/LuaJIT2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-luainterp --with-luajit
.endif
