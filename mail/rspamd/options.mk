# $NetBSD: options.mk,v 1.1 2017/03/20 14:15:16 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rspamd

PKG_SUPPORTED_OPTIONS=	gd

.include "../../mk/bsd.options.mk"

###
### Enable fuzzy matching for images
###
.if !empty(PKG_OPTIONS:Mgd)
.include "../../graphics/gd/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_GD=ON
.else
CMAKE_ARGS+=	-DENABLE_GD=OFF
.endif

