# $NetBSD: options.mk,v 1.1 2005/05/31 16:13:18 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libsndfile
PKG_SUPPORTED_OPTIONS=	oss

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Moss)
.include "../../mk/ossaudio.buildlink3.mk"
OSS_DEFS=	-DDEV_DSP=\\\"${DEVOSSAUDIO}\\\" -DUSE_OSS=1
MAKE_ENV+=	AM_CFLAGS=${OSS_DEFS:Q}
.endif
