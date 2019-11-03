# $NetBSD: options.mk,v 1.9 2019/11/03 10:39:13 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hdf5
PKG_SUPPORTED_OPTIONS=	szip threads
PKG_SUGGESTED_OPTIONS=	szip

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mszip)
CONFIGURE_ARGS+=	--with-szlib
.include "../../archivers/libaec/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-threadsafe
# XXX libraries should not be linked against -lpthread
.include "../../mk/pthread.buildlink3.mk"
.endif
