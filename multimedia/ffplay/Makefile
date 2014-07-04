# $NetBSD: Makefile,v 1.13 2014/07/04 10:33:41 adam Exp $

PKGNAME=	${DISTNAME:S/ffmpeg/ffplay/}
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	Simple SDL frontend for FFmpeg

DISTINFO_FILE=		${.CURDIR}/../ffmpeg/distinfo

CONFIGURE_ARGS+=	--disable-ffmpeg
CONFIGURE_ARGS+=	--disable-ffserver
CONFIGURE_ARGS+=	--disable-encoders
CONFIGURE_ARGS+=	--disable-decoders
CONFIGURE_ARGS+=	--disable-hwaccels
CONFIGURE_ARGS+=	--disable-muxers
CONFIGURE_ARGS+=	--disable-demuxers
CONFIGURE_ARGS+=	--disable-parsers
CONFIGURE_ARGS+=	--disable-bsfs
CONFIGURE_ARGS+=	--disable-protocols
CONFIGURE_ARGS+=	--disable-devices
#CONFIGURE_ARGS+=	--disable-filters
CONFIGURE_ARGS+=	--enable-ffplay

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ffplay ${DESTDIR}${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/ffmpeg/Makefile.common"
