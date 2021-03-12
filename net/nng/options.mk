# $NetBSD: options.mk,v 1.1 2021/03/12 02:28:08 khorben Exp $


PKG_OPTIONS_VAR=	PKG_OPTIONS.nng
PKG_SUPPORTED_OPTIONS=	doc static
PKG_SUGGESTED_OPTIONS+=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc shared static

.if !empty(PKG_OPTIONS:Mdoc)
.include "../../lang/ruby/rubyversion.mk"
BUILD_DEPENDS+=		${RUBY_PKGPREFIX}-asciidoctor-[0-9]*:../../textproc/ruby-asciidoctor
CMAKE_ARGS+=		-DNNG_ENABLE_DOC=1
CMAKE_ARGS+=		-DASCIIDOCTOR=${PREFIX}/bin/asciidoctor${RUBY_VER}
PLIST.doc=		yes
.endif

.if !empty(PKG_OPTIONS:Mstatic)
PLIST.static=		yes
.else
CMAKE_ARGS+=		-DBUILD_SHARED_LIBS:BOOL=ON
PLIST.shared=		yes
.endif
