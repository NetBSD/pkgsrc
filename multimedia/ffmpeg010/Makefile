# $NetBSD: Makefile,v 1.24 2016/06/23 17:24:51 maya Exp $

PKGNAME=	ffmpeg010-20150312.${DISTVERSION}
PKGREVISION=	3
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	Decoding, encoding and streaming software (v0.10)
LICENSE=	gnu-lgpl-v2.1

USE_GCC_RUNTIME=	yes

CONFIGURE_ARGS+=	--enable-avfilter
#CONFIGURE_ARGS+=	--enable-avfilter-lavf
CONFIGURE_ARGS+=	--enable-postproc
CONFIGURE_ARGS+=	--incdir=${PREFIX}/include/ffmpeg010
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/ffmpeg010
CONFIGURE_ARGS+=	--shlibdir=${PREFIX}/lib/ffmpeg010
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/ffmpeg010
#CONFIGURE_ARGS+=	--build-suffix=010
CONFIGURE_ARGS+=	--progs-suffix=010

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/ffmpeg010

INSTALLATION_DIRS=	lib share/examples/ffmpeg010 share/doc/ffmpeg010

CONF_FILES+=	${PREFIX}/share/examples/ffmpeg010/ffserver.conf \
		${PKG_SYSCONFDIR}/ffserver.conf

.include "../../mk/bsd.prefs.mk"

.include "../../mk/compiler.mk"

# disable asm on i386 for non-gcc and gcc < 4.2

.if ${MACHINE_ARCH} == "i386"
.if !empty(MACHINE_PLATFORM:MDarwin-*-i386) \
   || !empty(CC_VERSION:Mgcc-[123]*) \
   || !empty(CC_VERSION:Mgcc-4.[01].*) \
   || empty(CC_VERSION:Mgcc*)
CONFIGURE_ARGS+=	--disable-asm
.elif !empty(CC_VERSION:Mgcc-[456].*)
CFLAGS+=-mstackrealign -mpreferred-stack-boundary=4
.endif
.endif

TEST_TARGET=	check

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg010
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${DESTDIR}${PREFIX}/share/examples/ffmpeg010

.include "options.mk"

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-no-integrated-as
.endif

.include "../../multimedia/ffmpeg010/Makefile.common"
