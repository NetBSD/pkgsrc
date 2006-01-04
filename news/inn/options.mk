# $NetBSD: options.mk,v 1.1 2006/01/04 10:32:40 tron Exp $

PKG_OPTIONS_VAR= PKG_OPTIONS.inn
PKG_SUPPORTED_OPTIONS= python
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

###
### Python support for INN
###
.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=       --with-python
CONFIGURE_ENV+=         _PATH_PYTHON=${PYTHONBIN:Q}

.include "../../lang/python/application.mk"
.endif
