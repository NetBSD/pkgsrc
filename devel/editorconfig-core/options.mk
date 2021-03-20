# $NetBSD: options.mk,v 1.3 2021/03/20 18:52:45 adam Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.editorconfig-core
PKG_SUPPORTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

###
### Build and install html documentation and man pages
###
PLIST_VARS+=	doc
.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION=ON
CMAKE_ARGS+=	-DINSTALL_HTML_DOC=ON
PLIST.doc=	yes
.else
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION=OFF
.endif
