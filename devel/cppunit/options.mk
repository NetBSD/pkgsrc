# $NetBSD: options.mk,v 1.2 2023/06/06 12:40:35 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cppunit
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		doxygen>=1.6.3:../../devel/doxygen
CONFIGURE_ARGS+=	--enable-doxygen
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-doxygen
.endif
