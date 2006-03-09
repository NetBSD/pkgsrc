# $NetBSD: options.mk,v 1.3 2006/03/09 21:04:40 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libsndfile
PKG_SUPPORTED_OPTIONS=	oss

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Moss)
.include "../../mk/oss.buildlink3.mk"
OSS_DEFS=	-DDEV_DSP=\"${DEVOSSAUDIO:Q}\" -DUSE_OSS=1
MAKE_ENV+=	AM_CFLAGS=${OSS_DEFS:Q}
.endif
