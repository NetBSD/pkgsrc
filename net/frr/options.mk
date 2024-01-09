# $NetBSD: options.mk,v 1.3 2024/01/09 20:17:41 chopps Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.frr
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=	doc

PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

# Package-specific option-handling

###
### doc/man support
###
.if !empty(PKG_OPTIONS:Mdoc)
USE_TOOLS+=		makeinfo
CONFIGURE_ARGS+=	--enable-doc-html
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx>=7.0:../../textproc/py-sphinx
PLIST.doc=		yes
INFO_FILES=		yes
.else
CONFIGURE_ARGS+=	--disable-doc
.endif
