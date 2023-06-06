# $NetBSD: options.mk,v 1.4 2023/06/06 12:40:37 riastradh Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.editorconfig-core
PKG_SUPPORTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

###
### Build and install html documentation and man pages
###
PLIST_VARS+=	doc
.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION=ON
CMAKE_ARGS+=	-DINSTALL_HTML_DOC=ON
PLIST.doc=	yes
.else
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION=OFF
.endif
