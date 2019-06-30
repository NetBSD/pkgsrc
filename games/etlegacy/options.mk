# $NetBSD: options.mk,v 1.2 2019/06/30 23:33:40 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.etlegacy
PKG_SUPPORTED_OPTIONS=		lua ogg theora freetype sqlite3
PKG_SUGGESTED_OPTIONS=		lua ogg theora freetype sqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlua)
CMAKE_ARGS+=	-DFEATURE_LUA=ON
.include "../../lang/lua53/buildlink3.mk"
.else
CMAKE_ARGS+=	-DFEATURE_LUA=OFF
.endif

.if !empty(PKG_OPTIONS:Mogg)
CMAKE_ARGS+=	-DFEATURE_OGG_VORBIS=ON
.include "../../audio/libvorbis/buildlink3.mk"
.else
CMAKE_ARGS+=	-DFEATURE_OGG_VORBIS=OFF
.endif

.if !empty(PKG_OPTIONS:Mtheora)
CMAKE_ARGS+=	-DFEATURE_THEORA=ON
.include "../../multimedia/libtheora/buildlink3.mk"
.else
CMAKE_ARGS+=	-DFEATURE_THEORA=OFF
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
CMAKE_ARGS+=	-DFEATURE_FREETYPE=ON
.include "../../graphics/freetype2/buildlink3.mk"
.else
CMAKE_ARGS+=	-DFEATURE_FREETYPE=OFF
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
CMAKE_ARGS+=	-DFEATURE_DBMS=ON
.include "../../databases/sqlite3/buildlink3.mk"
.else
CMAKE_ARGS+=	-DFEATURE_DBMS=OFF
.endif
