# $NetBSD: Makefile,v 1.2 2004/05/25 21:49:26 wiz Exp $

DISTNAME=	ffmpeg-0.4.8
CATEGORIES=	multimedia net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ffmpeg/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://ffmpeg.sourceforge.net/
COMMENT=	MPEG decoding, encoding and streaming software

BUILD_DEPENDS+=	nasm>=0.98:../../devel/nasm

HAS_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES
MAKE_ENV+=	EXTRA_LIBS="${LIBGETOPT}" \
		FFSERVER_CONF=${PKG_SYSCONFDIR}/ffserver.conf \
		LOCALBASE="${LOCALBASE}"

CONFIGURE_ARGS=	--cc=${CC} --disable-grab --disable-mmx --prefix=${PREFIX}
CONFIGURE_ARGS+=	--disable-vhook

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ffmpeg \
		${PREFIX}/share/examples/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/libavcodec/apiexample.c \
		${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/doc/TODO \
		${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.txt \
		${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${PREFIX}/share/examples/ffmpeg
	# ffplay not installed
	${RM} ${PREFIX}/man/man1/ffplay.1

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
