# $NetBSD: options.mk,v 1.4 2024/06/10 15:46:07 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libopus
PKG_SUPPORTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PLIST.doc=		yes
PRINT_PLIST_AWK+=	{ if (/^share\/doc/) $$0 = "$${PLIST.doc}" $$0 }
PRINT_PLIST_AWK+=	{ if (/^man/) $$0 = "$${PLIST.doc}" $$0 }
.else
CONFIGURE_ARGS+=	--disable-doc
.endif
