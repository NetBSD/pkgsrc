# $NetBSD: options.mk,v 1.1.1.1 2008/12/03 00:44:49 bjs Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.celt
PKG_SUPPORTED_OPTIONS=	ogg
PKG_SUGGESTED_OPTIONS=	ogg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mogg)
CONFIGURE_ARGS+=	--with-ogg=${BUILDLINK_PREFIX.libogg:Q}
.  include "../../multimedia/libogg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ogg
.endif
