# $NetBSD: options.mk,v 1.2 2019/11/09 12:02:29 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fish
PKG_SUPPORTED_OPTIONS=		doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc
.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--with-doxygen=no
.endif
