# $NetBSD: options.mk,v 1.6 2015/07/13 09:33:13 morr Exp $

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
CONFIGURE_ARGS+=	--enable-pythoninterp
CONFIGURE_ENV+=		vi_cv_path_python=${PYTHONBIN}
.endif

.if !empty(PKG_OPTIONS:Mperl)
.include "../../lang/perl5/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-perlinterp
CONFIGURE_ENV+=		vi_cv_path_perl=${PERL5}
.endif

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
CONFIGURE_ARGS+=   --enable-luainterp
.endif

.if !empty(PKG_OPTIONS:Mluajit)
.include "../../lang/LuaJIT2/buildlink3.mk"
CONFIGURE_ARGS+=   --enable-luainterp --with-luajit
.endif
