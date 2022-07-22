# $NetBSD: options.mk,v 1.10 2022/07/22 14:50:32 thor Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hdf5
PKG_SUPPORTED_OPTIONS=	szip threads
PKG_SUGGESTED_OPTIONS=	szip

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mszip)
CONFIGURE_ARGS+=	--with-szlib
.include "../../archivers/libaec/buildlink3.mk"
.endif

# Threadsafe API is incompatible with high-level and C++ APIs.
PLIST_VARS+=	hl
.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-threadsafe --disable-hl
.include "../../mk/pthread.buildlink3.mk"
.else
PLIST.hl=	yes
.endif
