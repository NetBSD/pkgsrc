# $NetBSD: Makefile,v 1.109 2013/06/04 22:16:47 tron Exp $

PKGNAME=	ffmpeg-20130510.${DISTVERSION}
PKGREVISION=	2
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	Decoding, encoding and streaming software

CONFIGURE_ARGS+=	--enable-avfilter
#CONFIGURE_ARGS+=	--enable-avfilter-lavf
CONFIGURE_ARGS+=	--enable-postproc

INSTALLATION_DIRS=	lib share/examples/ffmpeg share/doc/ffmpeg

CONF_FILES+=	${PREFIX}/share/examples/ffmpeg/ffserver.conf \
		${PKG_SYSCONFDIR}/ffserver.conf

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MDarwin-*-i386) \
 || !empty(MACHINE_PLATFORM:MSunOS-*-i386)
CONFIGURE_ARGS+=	--disable-asm
.endif

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ARGS+=	--enable-cross-compile
CONFIGURE_ARGS+=	--target-os=${LOWER_OPSYS:Q}
CONFIGURE_ARGS+=	--arch=${MACHINE_ARCH:Q}
CONFIGURE_ARGS+=	--host-cc=${NATIVE_CC:Q}
CONFIGURE_ARGS+=	--host-ld=${NATIVE_CC:Q}
.endif

TEST_TARGET=	check

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${DESTDIR}${PREFIX}/share/examples/ffmpeg

.include "options.mk"

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-no-integrated-as
.endif

.include "../../multimedia/ffmpeg/Makefile.common"
