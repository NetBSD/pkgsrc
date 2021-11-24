# $NetBSD: options.mk,v 1.23 2021/11/24 14:17:58 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nmap

PKG_SUPPORTED_OPTIONS=	lua liblinear

.include "../../mk/bsd.prefs.mk"

#
# liblinear is used for IPv6 OS detection machine learning techniques.
#
# if nmap is built without liblinear, it will use an internal copy
# that does not depend on a fortran compiler, according to simonb@.
#
# NetBSD (as of 2021) does not include gfortran as part of GCC by
# default, so avoid building another copy of GCC as a dependency.
# Note that pkgsrc gcc only works on _some_ NetBSD architectures.
#

.if ${OPSYS} != "NetBSD"
PKG_SUGGESTED_OPTIONS=	liblinear
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	lua

.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_ACCEPTED=	53	# needs lua_isyieldable, introduced in Lua 5.3
.include "../../lang/lua/buildlink3.mk"
CONFIGURE_ARGS+=	--with-liblua=${BUILDLINK_PREFIX.lua}
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--without-liblua
.endif

.if !empty(PKG_OPTIONS:Mliblinear)
.include "../../math/liblinear/buildlink3.mk"
CONFIGURE_ARGS+=	--with-liblinear=${BUILDLINK_PREFIX.liblinear}
.else
CONFIGURE_ARGS+=	--without-liblinear
.endif
