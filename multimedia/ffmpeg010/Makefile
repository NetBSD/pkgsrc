# $NetBSD: Makefile,v 1.9 2012/12/14 19:23:43 drochner Exp $

PKGNAME=	ffmpeg010-20121026.${DISTVERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	Decoding, encoding and streaming software

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

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-asm
.endif

# "error: can't find a register in class 'GENERAL_REGS' while reloading 'asm'"
CFLAGS.SunOS+=	-DBROKEN_RELOCATIONS=1

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
