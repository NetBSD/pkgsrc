# $NetBSD: options.mk,v 1.1.1.1 2008/08/09 21:22:11 bjs Exp $
#
PKG_OPTIONS_VAR=		PKG_OPTIONS.libslang2
PKG_SUPPORTED_OPTIONS=		png oniguruma pcre

.include "../../mk/bsd.options.mk"

PLIST_VARS=	${PKG_SUPPORTED_OPTIONS}
.for var in ${PLIST_VARS}
PLIST.${var}=	yes
.endfor

.if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+=	--with-png=${BUILDLINK_PREFIX.png}
.  include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-png
.endif

.if !empty(PKG_OPTIONS:Mpcre)
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre}
.  include "../../devel/pcre/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pcre
.endif

.if !empty(PKG_OPTIONS:Moniguruma)
CONFIGURE_ARGS+=	--with-onig=${BUILDLINK_PREFIX.oniguruma}
.  include "../../textproc/oniguruma/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-onig
.endif

.if empty(PKG_OPTIONS:Moniguruma) && empty(PKG_OPTIONS:Mpcre)
USE_FEATURES+=		regcomp
.endif
