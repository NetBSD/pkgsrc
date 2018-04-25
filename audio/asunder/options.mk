# $NetBSD: options.mk,v 1.1 2018/04/25 12:57:24 triaxx Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.asunder
PKG_SUPPORTED_OPTIONS=	flac lame mac mpcenc opus vorbis wavpack
PKG_SUGGESTED_OPTIONS=	flac lame

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mflac)
DEPENDS+=	flac-[0-9]*:../../audio/flac
.endif

.if !empty(PKG_OPTIONS:Mlame)
DEPENDS+=	lame-[0-9]*:../../audio/lame
.endif

.if !empty(PKG_OPTIONS:Mmac)
DEPENDS+=	mac-[0-9]*:../../audio/mac
.endif

.if !empty(PKG_OPTIONS:Mmpcenc)
DEPENDS+=	musepack-[0-9]*:../../audio/musepack
.endif

.if !empty(PKG_OPTIONS:Mopus)
DEPENDS+=	opus-tools-[0-9]*:../../audio/opus-tools
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
DEPENDS+=	vorbis-tools-[0-9]*:../../audio/vorbis-tools
.endif

.if !empty(PKG_OPTIONS:Mwavpack)
DEPENDS+=	wavpack-[0-9]*:../../audio/wavpack
.endif
