# $NetBSD: Makefile,v 1.10 2004/10/03 00:13:02 tv Exp $

DISTNAME=	ffmpeg-0.4.8
PKGREVISION=	3
CATEGORIES=	multimedia net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ffmpeg/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://ffmpeg.sourceforge.net/
COMMENT=	MPEG decoding, encoding and streaming software

HAS_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES
USE_PKGINSTALL=	YES

CONF_FILES=	${PREFIX}/share/examples/ffmpeg/ffserver.conf \
		${PKG_SYSCONFDIR}/ffserver.conf

MAKE_ENV+=	EXTRA_LIBS="${LIBGETOPT}" \
		FFSERVER_CONF=${PKG_SYSCONFDIR}/ffserver.conf \
		LOCALBASE="${LOCALBASE}"

CONFIGURE_ARGS=		--cc=${CC} --prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-pp --disable-vhook --disable-debug

PKG_OPTIONS_VAR=	PKG_OPTIONS.ffmpeg
PKG_SUPPORTED_OPTIONS=	bktr lame mmx vorbis

.include "../../mk/bsd.options.mk"

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_MMX:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=   mmx
.endif

.include "../../mk/compiler.mk"

.if !empty(MACHINE_ARCH:Mi386)
.  if !empty(PKG_OPTIONS:Mmmx) && !empty(CC_VERSION:Mgcc*)
CFLAGS+=		-fomit-frame-pointer
.  else
CONFIGURE_ARGS+=	--disable-mmx
.  endif
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

.if !empty(PKG_OPTIONS:Mbktr)
post-extract:
	${CP} ${FILESDIR}/grab_bsdbktr.c ${WRKSRC}/libavformat

post-patch:
	${PATCH} --quiet -d ${WRKSRC} < ${FILESDIR}/bktr.diff
	${PATCH} --quiet -d ${WRKSRC} < ${FILESDIR}/ffmpeg.1.diff
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ffmpeg \
		${PREFIX}/share/doc/ffmpeg \
		${PREFIX}/include/ffmpeg/libpostproc
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
	${INSTALL_DATA} ${WRKSRC}/libavcodec/libpostproc/postprocess.h \
		${PREFIX}/include/ffmpeg/libpostproc

.include "../../devel/libgetopt/buildlink3.mk"

.if !empty(PKG_OPTIONS:Mlame)
CONFIGURE_ARGS+= --enable-mp3lame
.include "../../audio/lame/buildlink3.mk"
.else
CONFIGURE_ARGS+= --disable-mp3lame
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
CONFIGURE_ARGS+= --enable-vorbis
.include "../../audio/libvorbis/buildlink3.mk"
.else
CONFIGURE_ARGS+= --disable-vorbis
.endif

.include "../../mk/bsd.pkg.mk"
