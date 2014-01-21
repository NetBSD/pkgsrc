# $NetBSD: options.mk,v 1.1 2014/01/21 16:32:42 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pytables
PKG_SUPPORTED_OPTIONS=	lzo

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlzo)
PYSETUPBUILDARGS+=	--lzo=${BUILDLINK_PREFIX.lzo}
.include "../../archivers/lzo/buildlink3.mk"
.else
PYSETUPBUILDARGS+=	--lzo=XXX
.endif
