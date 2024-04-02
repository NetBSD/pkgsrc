# $NetBSD: options.mk,v 1.9 2024/04/02 22:37:53 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ImageMagick6
PKG_SUPPORTED_OPTIONS=		doc fontconfig ghostscript x11 jp2 djvu openexr
PKG_SUPPORTED_OPTIONS+=		wmf fpx pango
PKG_OPTIONS_REQUIRED_GROUPS=	policy
PKG_OPTIONS_GROUP.policy=	imagemagick-policy-limited imagemagick-policy-open imagemagick-policy-secure imagemagick-policy-websafe
PKG_SUGGESTED_OPTIONS=		doc fontconfig ghostscript x11 jp2 imagemagick-policy-open pango
PKG_OPTIONS_LEGACY_OPTS+=	jasper:jp2

.include "../../mk/bsd.options.mk"

PLIST_SRC+=		PLIST

.if !empty(PKG_OPTIONS:Mdoc)
PLIST_SRC+=		PLIST.doc
.else
CONFIGURE_ARGS+=	--disable-docs
.endif

.if !empty(PKG_OPTIONS:Mfontconfig)
CONFIGURE_ARGS+=	--with-fontconfig
.include "../../fonts/fontconfig/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-fontconfig
.endif

.if !empty(PKG_OPTIONS:Mghostscript)
CONFIGURE_ARGS+=	--with-gslib
.include "../../print/ghostscript/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gslib
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mjp2)
.include "../../graphics/openjpeg/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openjp2
.else
CONFIGURE_ARGS+=	--without-openjp2
.endif

.if !empty(PKG_OPTIONS:Mdjvu)
.include "../../graphics/djvulibre-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-djvu
.else
CONFIGURE_ARGS+=	--without-djvu
.endif

.if !empty(PKG_OPTIONS:Mopenexr)
.include "../../graphics/openexr/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openexr
.else
CONFIGURE_ARGS+=	--without-openexr
.endif

.if !empty(PKG_OPTIONS:Mwmf)
.include "../../graphics/libwmf/buildlink3.mk"
CONFIGURE_ARGS+=	--with-wmf
.else
CONFIGURE_ARGS+=	--without-wmf
.endif

.if !empty(PKG_OPTIONS:Mfpx)
.include "../../graphics/libfpx/buildlink3.mk"
CONFIGURE_ARGS+=	--with-fpx
.else
CONFIGURE_ARGS+=	--without-fpx
.endif

.if !empty(PKG_OPTIONS:Mfpx)
.include "../../graphics/pango/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pango
.else
CONFIGURE_ARGS+=	--without-pango
.endif

.if !empty(PKG_OPTIONS:Mimagemagick-policy-limited)
CONF_FILES+=		${EGDIR}/policy-limited.xml ${PKG_SYSCONFDIR}/policy.xml
.endif
.if !empty(PKG_OPTIONS:Mimagemagick-policy-open)
CONF_FILES+=		${EGDIR}/policy-open.xml ${PKG_SYSCONFDIR}/policy.xml
.endif
.if !empty(PKG_OPTIONS:Mimagemagick-policy-secure)
CONF_FILES+=		${EGDIR}/policy-secure.xml ${PKG_SYSCONFDIR}/policy.xml
.endif
.if !empty(PKG_OPTIONS:Mimagemagick-policy-websafe)
CONF_FILES+=		${EGDIR}/policy-websafe.xml ${PKG_SYSCONFDIR}/policy.xml
.endif
