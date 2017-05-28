# $NetBSD: options.mk,v 1.1 2017/05/28 19:43:46 nros Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.editorconfig-core
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

###
### Build and install html documentation and man pages
###
.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+= doxygen-[0-9]*:../../devel/doxygen
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION=ON
CMAKE_ARGS+=    -DINSTALL_HTML_DOC=ON
PLIST.doc=	yes
.else
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION=OFF
.endif
