# $NetBSD: Makefile,v 1.5 2013/10/30 07:08:23 adam Exp $

PKGNAME=	${DISTNAME:S/ffmpeg/ffmpeg2/}
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	Decoding, encoding and streaming software

CONFIGURE_ARGS+=	--enable-avfilter
#CONFIGURE_ARGS+=	--enable-avfilter-lavf
CONFIGURE_ARGS+=	--enable-postproc

INSTALLATION_DIRS=	lib/ffmpeg2 share/doc/ffmpeg2 share/examples/ffmpeg2

CONF_FILES+=	${PREFIX}/share/examples/ffmpeg2/ffserver.conf \
		${PKG_SYSCONFDIR}/ffserver.conf

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ARGS+=	--enable-cross-compile
CONFIGURE_ARGS+=	--arch=${MACHINE_ARCH}
CONFIGURE_ARGS+=	--host-cc=${NATIVE_CC:Q}
CONFIGURE_ARGS+=	--host-ld=${NATIVE_CC:Q}
CONFIGURE_ARGS+=	--target-os=${LOWER_OPSYS}
.endif

TEST_TARGET=	check

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg2
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${DESTDIR}${PREFIX}/share/examples/ffmpeg2

.include "options.mk"

.include "../../mk/compiler.mk"

# disable asm on i386 for non-gcc and gcc < 4.2
# no alignment options needed for gcc >= 4.6 on i386
.if ${MACHINE_ARCH} == "i386"
.  if !empty(MACHINE_PLATFORM:MDarwin-*-i386) \
   || !empty(MACHINE_PLATFORM:MSunOS-*-i386) \
   || !empty(CC_VERSION:Mgcc-[123]*) \
   || !empty(CC_VERSION:Mgcc-4.[01]*) \
   || empty(CC_VERSION:Mgcc*)
CONFIGURE_ARGS+=	--disable-asm
.  elif !empty(CC_VERSION:Mgcc-4.[2345]*)
CFLAGS+=		-mstackrealign -mpreferred-stack-boundary=4
.  endif
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-no-integrated-as
.endif

.include "../../multimedia/ffmpeg2/Makefile.common"
