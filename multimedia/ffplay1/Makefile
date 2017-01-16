# $NetBSD: Makefile,v 1.8 2017/01/16 23:45:13 wiz Exp $

PKGNAME=	${DISTNAME:S/ffmpeg/ffplay1/}
PKGREVISION=	5
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	Simple SDL frontend for FFmpeg

DISTINFO_FILE=		${.CURDIR}/../../multimedia/ffmpeg1/distinfo

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
	${INSTALL_PROGRAM} ${WRKSRC}/ffplay1 ${DESTDIR}${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.include "../../multimedia/ffmpeg1/Makefile.common"
