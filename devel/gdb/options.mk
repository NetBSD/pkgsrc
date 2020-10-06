# $NetBSD: options.mk,v 1.8 2020/10/06 21:13:38 mcf Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdb
PKG_SUPPORTED_OPTIONS=	python
PKG_SUGGESTED_OPTIONS=	python
PLIST_VARS+=		python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
PYTHON_VERSIONS_ACCEPTED=	 27
.include "../../lang/python/application.mk"
PLIST.python=	yes
.endif
