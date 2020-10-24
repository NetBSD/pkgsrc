# $NetBSD: options.mk,v 1.9 2020/10/24 18:22:08 kamil Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdb
PKG_SUPPORTED_OPTIONS=	python
PKG_SUGGESTED_OPTIONS=	python
PLIST_VARS+=		python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
PYTHON_VERSIONS_ACCEPTED=	 27 # Newer supported, but needs more tweaking
.include "../../lang/python/application.mk"
PLIST.python=	yes
.endif
