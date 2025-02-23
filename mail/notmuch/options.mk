# $NetBSD: options.mk,v 1.14 2025/02/23 16:59:21 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.notmuch
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS+=	doc

.include "../../mk/bsd.options.mk"

###
### documentation support
###
PLIST_VARS+=		doc
.if !empty(PKG_OPTIONS:Mdoc)
PLIST.doc=		yes
USE_TOOLS+=		perl
TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PYTHON_VERSIONS_INCOMPATIBLE=	39 310 # py-sphinx
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
.else
CONFIGURE_ARGS+=	--without-docs
CONFIGURE_ARGS+=	--without-api-docs
.endif
