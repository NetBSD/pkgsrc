# $NetBSD: options.mk,v 1.6 2010/02/06 22:19:00 gdt Exp $

PKG_OPTIONS_VAR=PKG_OPTIONS.hdf5
PKG_SUPPORTED_OPTIONS=	szip cxx threads
# szip is non-Free, so leave out by default
PKG_SUGGESTED_OPTIONS=	

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
