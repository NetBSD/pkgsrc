# $NetBSD: options.mk,v 1.1.1.1 2012/01/11 20:08:39 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.racoon2
PKG_SUPPORTED_OPTIONS=	iked kinkd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PKG_SUPPORTED_OPTIONS:=	${PKG_SUPPORTED_OPTIONS:Nkinkd}
PKG_SUGGESTED_OPTIONS:=	${PKG_SUGGESTED_OPTIONS:Nkinkd}
.else
PKG_SUGGESTED_OPTIONS=	iked kinkd
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Miked)
PLIST_SUBST+=		IKED=""
.else
CONFIGURE_ARGS+=	--disable-iked
PLIST_SUBST+=		IKED="@comment "
.endif

.if !empty(PKG_OPTIONS:Mkinkd)
PLIST_SUBST+=		KINKD=""
.else
CONFIGURE_ARGS+=	--disable-kinkd
PLIST_SUBST+=		KINKD="@comment "
.endif

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-natt
.endif
