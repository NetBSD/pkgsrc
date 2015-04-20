# $NetBSD: options.mk,v 1.1.1.1 2015/04/20 19:34:47 alnsn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-lupa
PKG_SUPPORTED_OPTIONS=	cython
PKG_SUGGESTED_OPTIONS+=	cython

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcython)
PYSETUPBUILDARGS+=	--with-cython
.include "../../devel/py-cython/buildlink3.mk"
.endif
