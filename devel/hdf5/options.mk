# $NetBSD: options.mk,v 1.12 2023/12/18 15:53:27 thor Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hdf5
PKG_SUPPORTED_OPTIONS=	szip threads hdf5-unsafe-threads
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

# You can still enable threads if you are adventurous. There
# are scientists like that. Not supported, but possible.
.if !empty(PKG_OPTIONS:Mhdf5-unsafe-threads)
CONFIGURE_ARGS+=       --enable-threadsafe --enable-unsupported
.include "../../mk/pthread.buildlink3.mk"
.endif
