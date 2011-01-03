# $NetBSD: options.mk,v 1.1 2011/01/03 09:13:26 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.psi
PKG_SUPPORTED_OPTIONS=	aspell enchant

.include "../../mk/bsd.options.mk"

# enable aspell
.if !empty(PKG_OPTIONS:Maspell)
CONFIGURE_ARGS+=	--with-aspell-inc=${BUILDLINK_PREFIX.aspell}/include
CONFIGURE_ARGS+=	--with-aspell-lib=${BUILDLINK_PREFIX.aspell}/lib
.include "../../textproc/aspell/buildlink3.mk"
.endif

# enable enchant
.if empty(PKG_OPTIONS:Menchant)
CONFIGURE_ARGS+=	--disable-enchant
.else
.include "../../textproc/enchant/buildlink3.mk"
.endif
