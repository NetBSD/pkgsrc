# $NetBSD: options.mk,v 1.2 2020/05/20 16:48:41 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnumeric
PKG_SUPPORTED_OPTIONS=	psiconv python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpsiconv)
.include "../../converters/psiconv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-psiconv
.endif

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=               --with-python
PYTHON_VERSIONS_ACCEPTED=      27 # not yet ported as of 1.12.47
PLIST_SRC+=		PLIST PLIST.python
.endif
