# $NetBSD: options.mk,v 1.2 2024/05/08 18:16:39 cheusov Exp $

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
.else
CONFIGURE_ARGS+=	--disable-doc
.endif
