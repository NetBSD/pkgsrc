# $NetBSD: options.mk,v 1.2 2015/04/19 22:54:55 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lv2
PKG_SUPPORTED_OPTIONS=	debug doc tests valgrind
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
BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
BUILD_DEPENDS+=		${PYPKGPREFIX}-rdflib-[0-9]*:../../textproc/py-rdflib
PLIST.doc=		yes
.else
BUILD_DOC=		# blank
.endif

.if !empty(PKG_OPTIONS:Mtests)
BUILD_TESTS=		--test
.else
BUILD_TESTS=		# blank
.endif

.if !empty(PKG_OPTIONS:Mvalgrind)
BUILD_VALGRIND=		--grind
BUILD_DEPENDS+=		valgrind-[0-9]*:../../devel/valgrind
.else
BUILD_VALGRIND=		# blank
.endif
