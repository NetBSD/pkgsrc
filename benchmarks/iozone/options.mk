# $NetBSD: options.mk,v 1.3 2022/05/28 11:39:57 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.iozone
PKG_SUPPORTED_OPTIONS=	threads

CHECK_BUILTIN.pthread:=	yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:=	no

.if !empty(USE_BUILTIN.pthread:M[Yy][Ee][Ss])
PKG_SUGGESTED_OPTIONS=	threads
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mthreads)
BUILDLINK_TRANSFORM+=	opt:-DNO_THREADS:-DTHREADS
PTHREAD_AUTO_VARS=	yes
PTHREAD_OPTS+=		require
.endif
