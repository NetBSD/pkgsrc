# $NetBSD: options.mk,v 1.1 2014/07/22 17:36:49 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libpgf
PKG_SUPPORTED_OPTIONS=	doc

PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=		doxygen>=1.8.7:../../devel/doxygen
PLIST.doc=		yes
CONFIGURE_ARGS+=	--enable-doc
.endif
