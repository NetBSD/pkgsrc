# $NetBSD: options.mk,v 1.3 2014/05/09 07:37:06 wiz Exp $

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
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.7.4
.include "../../lang/python/application.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.endif
