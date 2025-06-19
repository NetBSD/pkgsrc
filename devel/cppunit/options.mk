# $NetBSD: options.mk,v 1.3 2025/06/19 06:09:42 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cppunit
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		doxygen>=1.14:../../devel/doxygen
CONFIGURE_ARGS+=	--enable-doxygen
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-doxygen
.endif
