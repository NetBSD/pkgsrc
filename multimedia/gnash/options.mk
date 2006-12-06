# $NetBSD: options.mk,v 1.1 2006/12/06 00:13:05 xtraeme Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnash
PKG_SUPPORTED_OPTIONS=	klash

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mklash)
PLIST_SRC+=		${PKGDIR}/PLIST.klash
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
CONFIGURE_ARGS+=	\
	--with-plugindir=${PREFIX}/share/gnash/plugins
CONFIGURE_ARGS+=	--enable-klash
.else
CONFIGURE_ARGS+=	--disable-klash
CONFIGURE_ARGS+=	--disable-plugin
.endif

