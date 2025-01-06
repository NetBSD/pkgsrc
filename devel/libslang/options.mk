# $NetBSD: options.mk,v 1.1 2025/01/06 21:36:24 ktnb Exp $
#
PKG_OPTIONS_VAR=		PKG_OPTIONS.libslang
PKG_SUPPORTED_OPTIONS=		png oniguruma pcre

.include "../../mk/bsd.options.mk"

PLIST_VARS=	${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+=	--with-png=${BUILDLINK_PREFIX.png}
PLIST.png=		yes
.  include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-png
.endif

.if !empty(PKG_OPTIONS:Mpcre)
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre}
PLIST.pcre=		yes
.  include "../../devel/pcre/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pcre
.endif

.if !empty(PKG_OPTIONS:Moniguruma)
CONFIGURE_ARGS+=	--with-onig=${BUILDLINK_PREFIX.oniguruma}
PLIST.oniguruma=	yes
.  include "../../textproc/oniguruma/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-onig
.endif

.if empty(PKG_OPTIONS:Moniguruma) && empty(PKG_OPTIONS:Mpcre)
USE_FEATURES+=		regcomp
.endif
