# $NetBSD: options.mk,v 1.8 2007/09/05 18:58:19 shannonjr Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libprelude
PKG_SUPPORTED_OPTIONS=	perl python
PKG_OPTIONS.libprelude?=

.include "../../mk/bsd.options.mk"

###
### Whether to build with the perl and python plugins
###
###       python is needed for prewikka
###

PLIST_SRC=		${PKGDIR}/PLIST

.if !empty(PKG_OPTIONS:Mperl)
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
USE_TOOLS+=		perl:run
PLIST_SRC+=		${PKGDIR}/PLIST.perl
.include "../../lang/perl5/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-perl=no
.endif
.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PY_PATCHPLIST=		yes
PLIST_SRC+=		${PKGDIR}/PLIST.py
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.else
CONFIGURE_ARGS+=	--with-python=no
.endif
