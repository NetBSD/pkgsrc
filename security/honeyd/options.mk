# $NetBSD: options.mk,v 1.1 2005/01/14 21:44:33 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.honeyd
PKG_SUPPORTED_OPTIONS=	python rrdtool

.include "../../mk/bsd.options.mk"

###
### Add python support 
###
.if !empty(PKG_OPTIONS:Mpython)
.	include "../../lang/python/extension.mk"
CONFIGURE_ENV+=		_PATH_PYTHON=${PYTHONBIN}
.else
CONFIGURE_ARGS+=	--without-python
.endif

###
### Add RRDTool support
###
.if !empty(PKG_OPTIONS:Mrrdtool)
.	include "../../databases/rrdtool/buildlink3.mk"
.endif
