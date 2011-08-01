# $NetBSD: Makefile,v 1.4 2011/08/01 17:01:29 drochner Exp $

PKGNAME=	${DISTNAME:S/ffmpeg/ffplay/}
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	Simple SDL frontend for ffmpeg

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
