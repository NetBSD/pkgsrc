# $NetBSD: options.mk,v 1.2 2012/08/27 22:10:34 morr Exp $

PKG_SUPPORTED_OPTIONS+=	ruby python
PKG_OPTIONS_VAR=	PKG_OPTIONS.vim

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mruby)
.include "../../lang/ruby/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-rubyinterp
.endif

.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/pyversion.mk"
CONFIGURE_ARGS+=	--enable-pythoninterp
CONFIGURE_ENV+=		vi_cv_path_python=${PYTHONBIN}
.endif
