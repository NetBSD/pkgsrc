# $NetBSD: Makefile,v 1.4 2004/06/19 23:15:12 xtraeme Exp $

DISTNAME=	ffmpeg-0.4.8
CATEGORIES=	multimedia net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ffmpeg/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://ffmpeg.sourceforge.net/
COMMENT=	MPEG decoding, encoding and streaming software

HAS_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES
MAKE_ENV+=	EXTRA_LIBS="${LIBGETOPT}" \
		FFSERVER_CONF=${PKG_SYSCONFDIR}/ffserver.conf \
		LOCALBASE="${LOCALBASE}"

CONFIGURE_ARGS=		--cc=${CC} --disable-grab --prefix=${PREFIX}
CONFIGURE_ARGS+=	--disable-vhook --disable-debug

BUILD_DEFS+=		USE_MMX

.include "../../mk/compiler.mk"

.if !empty(MACHINE_ARCH:Mi386) && !empty(USE_MMX:M[Yy][Ee][Ss])
.  if !empty(CC_VERSION:Mgcc*)
CFLAGS+=	-fomit-frame-pointer
.  endif
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

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
