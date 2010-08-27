# $NetBSD: options.mk,v 1.1.1.1 2010/08/27 11:42:58 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qgis
PKG_SUPPORTED_OPTIONS=	python
PKG_SUGGESTED_OPTIONS+= python

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		python

.if empty(PKG_OPTIONS:Mpython)
CMAKE_ARGS+=		-DWITH_BINDINGS:BOOL=FALSE
.else
CMAKE_ARGS+=		-DWITH_BINDINGS:BOOL=TRUE
CMAKE_ARGS+=		-DSIP_BINARY_PATH:PATH=${BUILDLINK_PREFIX.py-sip}/bin
PLIST.python=		yes
.include "../../lang/python/application.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.endif
