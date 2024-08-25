# $NetBSD: options.mk,v 1.3 2024/08/25 06:19:07 wiz Exp $


PKG_OPTIONS_VAR=	PKG_OPTIONS.nng
PKG_SUPPORTED_OPTIONS=	doc static
PKG_SUGGESTED_OPTIONS+=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc shared static

.if !empty(PKG_OPTIONS:Mdoc)
.include "../../lang/ruby/rubyversion.mk"
TOOL_DEPENDS+=		${RUBY_PKGPREFIX}-asciidoctor-[0-9]*:../../textproc/ruby-asciidoctor
CMAKE_CONFIGURE_ARGS+=		-DNNG_ENABLE_DOC=1
CMAKE_CONFIGURE_ARGS+=		-DASCIIDOCTOR=${PREFIX}/bin/asciidoctor${RUBY_VER}
PLIST.doc=		yes
.endif

.if !empty(PKG_OPTIONS:Mstatic)
PLIST.static=		yes
.else
CMAKE_CONFIGURE_ARGS+=		-DBUILD_SHARED_LIBS:BOOL=ON
PLIST.shared=		yes
.endif
