# $NetBSD: options.mk,v 1.13 2024/08/04 15:56:01 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libkate
PKG_SUPPORTED_OPTIONS=	debug doc oggz valgrind vorbis
PKG_SUGGESTED_OPTIONS+=	oggz vorbis
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mdoc)
PLIST.doc=		yes
TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
.else
CONFIGURE_ARGS+=	--disable-doc
.endif

.if !empty(PKG_OPTIONS:Moggz)
.include "../../multimedia/liboggz/buildlink3.mk"
.endif

CONFIGURE_ENV+=		PYTHON=":"

.if !empty(PKG_OPTIONS:Mvalgrind)
TOOL_DEPENDS+=	valgrind-[0-9]*:../../devel/valgrind
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
TOOL_DEPENDS+=	vorbis-tools-[0-9]*:../../audio/vorbis-tools
.endif
