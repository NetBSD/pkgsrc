# $NetBSD: options.mk,v 1.8 2020/07/29 10:44:32 jmcneill Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ghostscript
PKG_SUPPORTED_OPTIONS=	x11 cups debug fontconfig disable-compile-inits utf8
PKG_SUGGESTED_OPTIONS=	x11 cups fontconfig

.include "../../mk/bsd.options.mk"

# (no_cidfmap)	when --disable-compile-inits selected,
#		cidfmap is renamed to cidfmap.dist
PLIST_VARS+=		no_cidfmap

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mcups)
CONFIGURE_ARGS+=	--enable-cups

# # Because nothing is installed, this is not necessary.  It remains in
# # case a later version does install something.
# SUBST_CLASSES+=		cupsetc
# SUBST_STAGE.cupsetc=	post-extract
# SUBST_MESSAGE.cupsetc=	Fixing CUPS etc directory path to install as example
# SUBST_FILES.cupsetc=	cups/cups.mak
# SUBST_SED.cupsetc=	-e 's|$$(CUPSSERVERROOT)|${CUPS_EGDIR}|g'

.include "../../print/libcups/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mfontconfig)
.include "../../fonts/fontconfig/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-fontconfig
.endif

# Please note the same if condition is in post-extract: target in Makefile
.if !empty(PKG_OPTIONS:Mdisable-compile-inits)
CONFIGURE_ARGS+=	--disable-compile-inits
PLIST.no_cidfmap=	YES
.endif

.if !empty(PKG_OPTIONS:Mutf8)
.include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libiconv=${ICONV_TYPE}
.else
CONFIGURE_ARGS+=	--with-libiconv=no
.endif
