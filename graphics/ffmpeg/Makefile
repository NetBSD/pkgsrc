# $NetBSD: Makefile,v 1.10 2004/04/24 00:01:05 wiz Exp $

DISTNAME=	ffmpeg-0.4.5
PKGREVISION=	2
CATEGORIES=	graphics net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ffmpeg/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://ffmpeg.sourceforge.net/
COMMENT=	MPEG decoding, encoding and streaming software

BUILD_DEPENDS+=	nasm>=0.98:../../devel/nasm

WRKSRC=		${WRKDIR}/ffmpeg
HAS_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES
MAKE_ENV+=	EXTRA_LIBS="${LIBGETOPT}" \
		FFSERVER_CONF=${PKG_SYSCONFDIR}/ffserver.conf \
		LOCALBASE="${LOCALBASE}"

CONFIGURE_ARGS=	--cc=${CC} --disable-grab --disable-mmx --prefix=${PREFIX}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/libav
	${INSTALL_DATA_DIR} ${PREFIX}/include/libavcodec
	${INSTALL_DATA_DIR} ${PREFIX}/include/libavcodec/i386
	${INSTALL_DATA_DIR} ${PREFIX}/include/libavcodec/libac3
	${INSTALL_DATA} ${WRKSRC}/libav/*.h ${PREFIX}/include/libav
	${INSTALL_DATA} ${WRKSRC}/libavcodec/*.h ${PREFIX}/include/libavcodec
	${INSTALL_DATA} ${WRKSRC}/libavcodec/i386/*.h \
		${PREFIX}/include/libavcodec/i386
	${INSTALL_DATA} ${WRKSRC}/libavcodec/libac3/*.h \
		${PREFIX}/include/libavcodec/libac3
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ffmpeg \
		${PREFIX}/share/examples/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/libavcodec/apiexample.c \
		${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/doc/* \
		${PREFIX}/share/doc/ffmpeg
	${MV} ${PREFIX}/share/doc/ffmpeg/ffserver.conf \
		${PREFIX}/share/examples/ffmpeg

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
