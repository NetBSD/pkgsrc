# $NetBSD: options.mk,v 1.4 2006/06/06 12:19:30 shannonjr Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libprelude
PKG_SUPPORTED_OPTIONS=	perl python

.include "../../mk/bsd.options.mk"

###
### Whether to build with the perl and python plugins
###
###       python is needed for prewikka
###

.if !empty(PKG_OPTIONS:Mperl)
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
CONFIGURE_ARGS+=	--with-swig=/usr/pkg/bin/swig
USE_TOOLS+=		perl:run
#REPLACE_PERL+=		${WRKSRC}/bindings/perl/Makefile.PL
.include "../../devel/swig/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-perl=no
.endif
.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PY_PATCHPLIST=		yes
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.else
CONFIGURE_ARGS+=	--with-python=no
.endif
