# $NetBSD: options.mk,v 1.3 2020/05/19 17:05:44 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lv2
PKG_SUPPORTED_OPTIONS=	debug doc tests valgrind
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
BUILD_DEBUG=		--debug
.else
BUILD_DEBUG=		# blank
.endif

.if !empty(PKG_OPTIONS:Mdoc)
PLIST_SRC+=		PLIST.doc
BUILD_DOC=		--docs
BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
BUILD_DEPENDS+=		${PYPKGPREFIX}-rdflib-[0-9]*:../../textproc/py-rdflib
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
