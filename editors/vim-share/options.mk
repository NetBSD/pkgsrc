# $NetBSD: options.mk,v 1.3 2014/02/15 03:37:27 schmonz Exp $

PKG_SUPPORTED_OPTIONS+=	ruby python perl
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
