# $NetBSD: Makefile,v 1.7 2012/03/14 14:31:48 wiz Exp $

PKGNAME=	${DISTNAME:S/ffmpeg/ffplay/}
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	Simple SDL frontend for FFmpeg

DISTINFO_FILE=		${.CURDIR}/../ffmpeg/distinfo

PKG_DESTDIR_SUPPORT=    user-destdir

CONFIGURE_ARGS+=        --enable-ffplay \
			--disable-ffmpeg \
			--disable-ffserver \
			--disable-encoders \
			--disable-decoders \
			--disable-hwaccels \
			--disable-muxers \
			--disable-demuxers \
			--disable-parsers \
			--disable-bsfs \
			--disable-protocols \
			--disable-devices
#			--disable-filters

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ffplay ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/ffplay.1 \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/ffmpeg/Makefile.common"
