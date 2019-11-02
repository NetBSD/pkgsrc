# $NetBSD: options.mk,v 1.8 2019/11/02 19:57:01 tnn Exp $

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
.include "../../lang/lua/buildlink3.mk"
CONFIGURE_ARGS+=   --enable-luainterp
.endif

.if !empty(PKG_OPTIONS:Mluajit)
.include "../../lang/LuaJIT2/buildlink3.mk"
CONFIGURE_ARGS+=   --enable-luainterp --with-luajit
.endif
