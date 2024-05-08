# $NetBSD: options.mk,v 1.3 2024/05/08 18:50:24 cheusov Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.jemalloc
PKG_SUPPORTED_OPTIONS=		debug doc
PKG_SUGGESTED_OPTIONS=		doc

PLIST_VARS+=			doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
PLIST.doc=		yes
BUILD_TARGET+=		dist
.else
CONFIGURE_ARGS+=	--disable-doc
.endif
