# $NetBSD: Makefile,v 1.78 2011/11/28 11:00:28 drochner Exp $

# XXX This is release 0.7.8 but we had date-based pkgnames before.
PKGNAME=	ffmpeg-20111121.${DISTVERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	Decoding, encoding and streaming software

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-avfilter
#CONFIGURE_ARGS+=	--enable-avfilter-lavf
CONFIGURE_ARGS+=	--enable-postproc
CONFIGURE_ARGS+=	--enable-libvorbis
CONFIGURE_ARGS+=	--enable-libmp3lame
CONFIGURE_ARGS+=	--enable-libx264

INSTALLATION_DIRS=	lib share/examples/ffmpeg share/doc/ffmpeg

CONF_FILES+=	${PREFIX}/share/examples/ffmpeg/ffserver.conf \
		${PKG_SYSCONFDIR}/ffserver.conf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-asm
.endif

TEST_TARGET=	check

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/doc/TODO \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${DESTDIR}${PREFIX}/share/examples/ffmpeg

.include "options.mk"

# "lame-3.98" isn't compatible with "ffmpeg" which breaks audio encoding.
BUILDLINK_ABI_DEPENDS.lame+=	lame>=3.98.2nb1

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-no-integrated-as
.endif

.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/ffmpeg/Makefile.common"
