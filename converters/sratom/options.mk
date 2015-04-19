# $NetBSD: options.mk,v 1.1 2015/04/19 23:45:06 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sratom
PKG_SUPPORTED_OPTIONS=	debug doc tests
PKG_SUGGESTED_OPTIONS+=	# blank
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
BUILD_DEBUG=		--debug
.else
BUILD_DEBUG=		# blank
.endif

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DOC=		--docs
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
BUILD_DEPENDS+=		graphviz-[0-9]*:../../graphics/graphviz
PLIST.doc=		yes
.else
BUILD_DOC=		# blank
.endif

.if !empty(PKG_OPTIONS:Mtests)
BUILD_TESTS=		--test
.else
BUILD_TESTS=		# blank
.endif
