# $NetBSD: options.mk,v 1.7 2018/11/22 14:56:07 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.enchant
PKG_SUPPORTED_OPTIONS=	aspell enchant-zemberek hunspell ispell
PKG_SUGGESTED_OPTIONS=	hunspell

.include "../../mk/bsd.options.mk"

PLIST_VARS+=            aspell
.if !empty(PKG_OPTIONS:Maspell)
CONFIGURE_ARGS+=	--enable-aspell
.include "../../textproc/aspell/buildlink3.mk"
PLIST.aspell=		yes
.else
CONFIGURE_ARGS+=	--disable-aspell
.endif

.if !empty(PKG_OPTIONS:Menchant-zemberek)
CONFIGURE_ARGS+=	--enable-zemberek
.include "../../sysutils/dbus-glib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-zemberek
.endif

PLIST_VARS+=            hunspell
.if !empty(PKG_OPTIONS:Mhunspell)
.include "../../textproc/hunspell/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-myspell
CONFIGURE_ARGS+=	--with-myspell-dir=${BUILDLINK_PREFIX.hunspell}/share/hunspell
DEPENDS+=		hunspell-en_US-[0-9]*:../../textproc/hunspell-en_US
PLIST.hunspell=		yes
.else
CONFIGURE_ARGS+=	--disable-myspell
.endif

PLIST_VARS+=            ispell
.if !empty(PKG_OPTIONS:Mispell)
CONFIGURE_ARGS+=	--enable-ispell
PLIST.ispell=		yes
DEPENDS+=		ispell-base>=3.3.02:../../textproc/ispell-base
.else
CONFIGURE_ARGS+=	--disable-ispell
.endif
