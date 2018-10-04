# $NetBSD: options.mk,v 1.1 2018/10/04 16:01:40 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hivex
PKG_SUPPORTED_OPTIONS=	ocaml perl python readline ruby
PKG_SUGGESTED_OPTIONS=	ocaml

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		ocaml
.if !empty(PKG_OPTIONS:Mocaml)
PLIST.ocaml=		yes
INSTALL_ENV+=		OCAML_SITELIBDIR=${OCAML_SITELIBDIR}
OCAML_USE_FINDLIB=	yes
CONFIGURE_ARGS+=	--enable-ocaml
.include "../../mk/ocaml.mk"
.else
CONFIGURE_ARGS+=	--disable-ocaml
.endif

PLIST_VARS+=		perl
.if !empty(PKG_OPTIONS:Mperl)
USE_TOOLS+=		perl:run
PLIST.perl=		yes
CONFIGURE_ARGS+=	--enable-perl
DEPENDS+=		p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
PERL5_PACKLIST=		auto/Win/Hivex/.packlist
REPLACE_PERL+=		regedit/hivexregedit
.include "../../lang/perl5/packlist.mk"
.include "../../lang/perl5/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-perl
.endif

PLIST_VARS+=		python
.if !empty(PKG_OPTIONS:Mpython)
PLIST.python=		yes
CONFIGURE_ARGS+=	--enable-python
PY_PATCHPLIST=		yes
.include "../../lang/python/extension.mk"
.else
CONFIGURE_ARGS+=	--disable-python
.endif

.if !empty(PKG_OPTIONS:Mreadline)
CONFIGURE_ARGS+=	--with-readline
.include "../../devel/readline/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-readline
.endif

PLIST_VARS+=		ruby
.if !empty(PKG_OPTIONS:Mruby)
PLIST.ruby=		yes
CONFIGURE_ARGS+=	--enable-ruby
CONFIGURE_ENV+=		ac_cv_prog_RUBY=${PREFIX}/bin/${RUBY_NAME}
CONFIGURE_ENV+=		ac_cv_prog_RAKE=${PREFIX}/bin/${RAKE_NAME}
.include "../../lang/ruby/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ruby
.endif
