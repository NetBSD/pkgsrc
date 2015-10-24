# $NetBSD: options.mk,v 1.2 2015/10/24 21:20:10 joerg Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pspp
PKG_SUPPORTED_OPTIONS=		pgsql x11
PKG_SUGGESTED_OPTIONS=		x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes

#CONFIGURE_ARGS+=	--without-libplot # :(
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gui --without-libplot
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-libpq
.include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libpq
.endif
