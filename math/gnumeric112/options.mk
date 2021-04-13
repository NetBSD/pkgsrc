# $NetBSD: options.mk,v 1.4 2021/04/13 09:11:27 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnumeric
PKG_SUPPORTED_OPTIONS=	psiconv python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpsiconv)
.include "../../converters/psiconv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-psiconv
.endif

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python
PLIST_SRC+=		PLIST PLIST.python
.endif
