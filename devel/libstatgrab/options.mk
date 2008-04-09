# $NetBSD: options.mk,v 1.2 2008/04/09 16:21:48 jlam Exp $

PKG_OPTIONS_VAR=	libstatgrab
PKG_SUPPORTED_OPTIONS=	saidar statgrab
PKG_DEFAULT_OPTIONS=	saidar statgrab

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		saidar statgrab

.if defined(WITHOUT_SAIDAR)
PKG_OPTIONS_DEPRECATED_WARNINGS+="Deprecated variable WITHOUT_SAIDAR used; use \`\`-saidar'' instead."
.endif
.if defined(WITHOUT_STATGRAB)
PKG_OPTIONS_DEPRECATED_WARNINGS+="Deprecated variable WITHOUT_STATGRAB used; use \`\`-statgrab'' instead."
.endif

.if !empty(PKG_OPTIONS:Mstatgrab)
PLIST.statgrab=		yes
.else
CONFIGURE_ARGS+=	--disable-statgrab
.endif

.if !empty(PKG_OPTIONS:Msaidar)
PLIST.saidar=		yes
.  include "../../devel/ncurses/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-saidar
.endif
