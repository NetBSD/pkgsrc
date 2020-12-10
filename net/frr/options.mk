# $NetBSD: options.mk,v 1.1 2020/12/10 16:43:24 kardel Exp $

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
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx>=2.4.4:../../textproc/py-sphinx
PLIST.doc=		yes
INFO_FILES=		yes
.else
CONFIGURE_ARGS+=	--disable-doc
.endif
