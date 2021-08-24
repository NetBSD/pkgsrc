# $NetBSD: options.mk,v 1.3 2021/08/24 10:05:50 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-lupa
PKG_SUPPORTED_OPTIONS=	cython luajit
PKG_SUGGESTED_OPTIONS+=	cython

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcython)
PYSETUPBUILDARGS+=	--with-cython
.include "../../devel/py-cython/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mluajit)
.include "../../lang/LuaJIT2/buildlink3.mk"
.else
LUA_VERSIONS_ACCEPTED=	53 51 52
.include "../../lang/lua/buildlink3.mk"
.endif
