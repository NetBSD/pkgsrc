# $NetBSD: options.mk,v 1.6 2019/04/26 13:13:49 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdb
PKG_SUPPORTED_OPTIONS=	python
PKG_SUGGESTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37
.include "../../lang/python/application.mk"
.endif
