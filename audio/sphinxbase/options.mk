# $NetBSD: options.mk,v 1.1 2014/09/05 10:13:21 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sphinxbase
PKG_SUPPORTED_OPTIONS=	samplerate sndfile threads
PKG_SUGGESTED_OPTIONS=	samplerate sndfile

.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "native"
PKG_SUGGESTED_OPTIONS+=	threads
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msamplerate)
.include "../../audio/libsamplerate/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msndfile)
.include "../../audio/libsndfile/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
