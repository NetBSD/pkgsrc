# $NetBSD: options.mk,v 1.3 2023/06/06 12:40:17 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lilv
PKG_SUPPORTED_OPTIONS=	debug doc tests
PKG_SUGGESTED_OPTIONS+=	# blank
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
WAF_ARGS+=		--debug
.endif

.if !empty(PKG_OPTIONS:Mdoc)
WAF_ARGS+=		--docs
TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
TOOL_DEPENDS+=		graphviz-[0-9]*:../../graphics/graphviz
PLIST.doc=		yes
.endif

.if !empty(PKG_OPTIONS:Mtests)
WAF_ARGS+=		--test
.endif
