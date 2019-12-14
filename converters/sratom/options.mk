# $NetBSD: options.mk,v 1.2 2019/12/14 17:53:39 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sratom
PKG_SUPPORTED_OPTIONS=	debug doc tests
PKG_SUGGESTED_OPTIONS+=	# blank
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
WAF_ARGS+=		--debug
.endif

.if !empty(PKG_OPTIONS:Mdoc)
WAF_ARGS+=		--docs
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
BUILD_DEPENDS+=		graphviz-[0-9]*:../../graphics/graphviz
PLIST.doc=		yes
.endif

.if !empty(PKG_OPTIONS:Mtests)
WAF_ARGS+=		--test
.endif
