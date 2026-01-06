# $NetBSD: options.mk,v 1.7 2026/01/06 11:31:36 wiz Exp $

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
PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx>=9:../../textproc/py-sphinx
PLIST.doc=		yes
INFO_FILES=		yes
.else
CONFIGURE_ARGS+=	--disable-doc
.endif
