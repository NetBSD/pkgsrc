# $NetBSD: options.mk,v 1.1 2013/05/09 00:40:12 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.liboggz
PKG_SUPPORTED_OPTIONS=	doc valgrind
PKG_SUGGESTED_OPTIONS+=	# blank
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	HAVE_DOXYGEN=no
.endif

.if !empty(PKG_OPTIONS:Mvalgrind)
BUILD_DEPENDS+=	valgrind-[0-9]*:../../devel/valgrind
CONFIGURE_ARGS+=	--enable-valgrind-testing
.else
CONFIGURE_ARGS+=	--disable-valgrind-testing
.endif
