# $NetBSD: options.mk,v 1.4 2017/01/01 14:43:30 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdb
PKG_SUPPORTED_OPTIONS=	python
PKG_SUGGESTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36
.include "../../lang/python/application.mk"
.endif
