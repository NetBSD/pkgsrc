# $NetBSD: options.mk,v 1.3 2006/07/22 04:46:15 rillig Exp $

PKG_OPTIONS_VAR=PKG_OPTIONS.hdf5
PKG_SUPPORTED_OPTIONS=	szip cxx threads
PKG_SUGGESTED_OPTIONS=	szip

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mszip)
CONFIGURE_ARGS+=	--with-szlib
.include "../../archivers/szip/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcxx)
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--enable-cxx
PLIST_SUBST+=		CXX=
.else
PLIST_SUBST+=		CXX="@comment "
.endif

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-threadsafe
.include "../../mk/pthread.buildlink3.mk"
.endif
