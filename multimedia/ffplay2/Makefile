# $NetBSD: Makefile,v 1.37 2024/01/27 02:54:36 riastradh Exp $

PKGNAME=	${DISTNAME:S/ffmpeg/ffplay2/}
PKGREVISION=	7
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ffmpeg.org/
COMMENT=	Simple SDL frontend for FFmpeg

DISTINFO_FILE=		${.CURDIR}/../ffmpeg2/distinfo

CONFIGURE_ARGS+=	--disable-ffmpeg
CONFIGURE_ARGS+=	--disable-ffprobe
CONFIGURE_ARGS+=	--disable-ffserver
CONFIGURE_ARGS+=	--disable-encoders
CONFIGURE_ARGS+=	--disable-decoders
CONFIGURE_ARGS+=	--disable-htmlpages
CONFIGURE_ARGS+=	--disable-hwaccels
CONFIGURE_ARGS+=	--disable-muxers
CONFIGURE_ARGS+=	--disable-demuxers
CONFIGURE_ARGS+=	--disable-parsers
CONFIGURE_ARGS+=	--disable-bsfs
CONFIGURE_ARGS+=	--disable-protocols
CONFIGURE_ARGS+=	--disable-devices
CONFIGURE_ARGS+=	--disable-filters
CONFIGURE_ARGS+=	--enable-ffplay
CONFIGURE_ARGS+=	--enable-dct
CONFIGURE_ARGS+=	--enable-mdct
CONFIGURE_ARGS+=	--enable-rdft

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ffplay2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/ffplay2.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../multimedia/ffmpeg2/Makefile.common"
