# $NetBSD: options.mk,v 1.8 2017/05/13 20:25:44 alnsn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tor
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS+=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc

###
### This enables the build of manual pages. It requires asciidoc
### at build time, which comes with a tail of dependencies and
### may not be wanted under certain circumstances.
###
.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=		asciidoc>=8.3.3:../../textproc/asciidoc
CONFIGURE_ARGS+=	--enable-asciidoc
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-asciidoc
.endif
