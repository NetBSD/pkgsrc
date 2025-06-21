# $NetBSD: options.mk,v 1.5 2025/06/21 15:07:31 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.liboggz
PKG_SUPPORTED_OPTIONS=	doc valgrind
PKG_SUGGESTED_OPTIONS+=	# blank
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		doxygen>=1.14:../../devel/doxygen
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
