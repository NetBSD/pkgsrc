# $NetBSD: options.mk,v 1.6 2006/08/31 13:04:54 rillig Exp $

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
USE_TOOLS+=		perl:run
GENERATE_PLIST+=	cat ${PKGDIR}/PLIST.perl;
.include "../../lang/perl5/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-perl=no
.endif
.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PY_PATCHPLIST=		yes
GENERATE_PLIST+=	cat ${PKGDIR}/PLIST.py;
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.else
CONFIGURE_ARGS+=	--with-python=no
.endif
