# $NetBSD: options.mk,v 1.1 2017/06/05 10:41:28 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdb
PKG_SUPPORTED_OPTIONS=	python
PKG_SUGGESTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36
.include "../../lang/python/application.mk"
.endif
