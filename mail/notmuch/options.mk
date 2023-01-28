# $NetBSD: options.mk,v 1.12 2023/01/28 13:09:28 ryoon Exp $

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
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
.else
CONFIGURE_ARGS+=	--without-docs
CONFIGURE_ARGS+=	--without-api-docs
.endif
