# $NetBSD: options.mk,v 1.4 2024/07/22 07:26:14 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.liboggz
PKG_SUPPORTED_OPTIONS=	doc valgrind
PKG_SUGGESTED_OPTIONS+=	# blank
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	HAVE_DOXYGEN=false
.endif

.if !empty(PKG_OPTIONS:Mvalgrind)
TOOL_DEPENDS+=		valgrind-[0-9]*:../../devel/valgrind
CONFIGURE_ARGS+=	--enable-valgrind-testing
.else
CONFIGURE_ARGS+=	--disable-valgrind-testing
.endif
