# $NetBSD: options.mk,v 1.1 2026/11/17 12:04:13 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.edje
PKG_SUPPORTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	python

.if !empty(PKG_OPTIONS:Mpython)
PLIST.python=	yes
REPLACE_PYTHON+=	utils/inkscape2edc
.include	"../../lang/python/application.mk"
.else
CONFIGURE_ARGS+=	PYTHON=:
.endif
