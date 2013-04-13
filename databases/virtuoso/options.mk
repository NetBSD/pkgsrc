# $NetBSD: options.mk,v 1.1 2013/04/13 13:16:02 jaapb Exp $

PKG_OPTIONS_VAR=                PKG_OPTIONS.virtuoso
PKG_SUPPORTED_OPTIONS=          imagemagick ldap

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# Package-specific option-handling
PLIST_VARS=	im

###
### ImageMagick support
###
.if !empty(PKG_OPTIONS:Mimagemagick)
CONFIGURE_ARGS+=	--enable-imagemagick=${PREFIX}
PLIST.im=	yes
.include "../../graphics/ImageMagick/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-imagemagick
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--enable-openldap=${PREFIX}
.include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-openldap
.endif
