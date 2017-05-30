# $NetBSD: options.mk,v 1.2 2017/05/30 21:59:56 alnsn Exp $

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
.include "../../lang/lua/buildlink3.mk"
.endif
