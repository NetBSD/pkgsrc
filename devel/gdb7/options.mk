# $NetBSD: options.mk,v 1.5 2020/08/28 11:02:23 micha Exp $

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
