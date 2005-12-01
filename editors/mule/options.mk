# $NetBSD: options.mk,v 1.1 2005/12/01 17:34:41 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mule
PKG_SUPPORTED_OPTIONS=	canna wnn4
PKG_SUGGESTED_OPTIONS=	canna wnn4

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwnn4)
.include "../../inputmethod/ja-freewnn-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-wnn4
CONFIGURE_ARGS+=	--wnn-includes=${BUILDLINK_PREFIX.ja-FreeWnn-lib}/include/wnn
CONFIGURE_ARGS+=	--wnn-libraries=${BUILDLINK_PREFIX.ja-FreeWnn-lib}/lib
.endif

.if !empty(PKG_OPTIONS:Mcanna)
.include "../../inputmethod/canna-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--canna
CONFIGURE_ARGS+=	--canna-includes=${BUILDLINK_PREFIX.Canna-lib}/include
CONFIGURE_ARGS+=	--canna-libraries=${BUILDLINK_PREFIX.Canna-lib}/lib
.endif
