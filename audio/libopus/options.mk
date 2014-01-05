# $NetBSD: options.mk,v 1.1 2014/01/05 19:56:50 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opus
PKG_SUPPORTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-doc
.endif
