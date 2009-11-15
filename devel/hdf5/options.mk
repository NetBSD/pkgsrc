# $NetBSD: options.mk,v 1.5 2009/11/15 15:50:50 drochner Exp $

PKG_OPTIONS_VAR=PKG_OPTIONS.hdf5
PKG_SUPPORTED_OPTIONS=	szip cxx threads
PKG_SUGGESTED_OPTIONS=	szip

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cxx

.if !empty(PKG_OPTIONS:Mszip)
CONFIGURE_ARGS+=	--with-szlib
.include "../../archivers/szip/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcxx)
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--enable-cxx
PLIST.cxx=		yes
.endif

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-threadsafe
# XXX libraries should not be linked against -lpthread
.include "../../mk/pthread.buildlink3.mk"
.endif
