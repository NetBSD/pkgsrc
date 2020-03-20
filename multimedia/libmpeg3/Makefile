# $NetBSD: Makefile,v 1.25 2020/03/20 11:58:04 nia Exp $
#

DISTNAME=	libmpeg3-1.8-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	devel audio graphics multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=heroines/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://heroines.sourceforge.net/libmpeg3.php3
COMMENT=	MPEG decoding library and tools

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386" && ${OPSYS} != "Darwin")
MAKE_ENV+=		USE_MMX=1
MAKE_ENV+=		USE_CSS=1
BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm
.else
MAKE_ENV.DragonFly+=	USE_MMX=0
MAKE_ENV.DragonFly+=	USE_CSS=0
.endif

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

PTHREAD_AUTO_VARS=	yes
PTHREAD_OPTS+=		require

post-configure:
	${ECHO} "CFLAGS+=-O2" >>${WRKSRC}/global_config
	${ECHO} "CFLAGS+=-I${BUILDLINK_DIR}/include" >>${WRKSRC}/global_config
	${ECHO} "CFLAGS+=-D_FILE_OFFSET_BITS=64" >>${WRKSRC}/global_config

INSTHDRS=	bitstream.h libmpeg3.h mpeg3atrack.h mpeg3css.h \
		mpeg3demux.h mpeg3io.h mpeg3private.h \
		mpeg3private.inc mpeg3title.h mpeg3vtrack.h timecode.h
AINSTHDRS=	ac3.h mpeg3audio.h
VINSTHDRS=	idct.h mpeg3video.h slice.h
INSTBINS=	mpeg3cat mpeg3peek mpeg3toc mpeg3dump

INSTALLATION_DIRS=	bin include/mpeg3/audio include/mpeg3/video lib \
			share/doc/libmpeg3

do-install:
	for f in ${INSTBINS}; do \
		${INSTALL_PROGRAM} ${WRKSRC}/work/$$f ${DESTDIR}${PREFIX}/bin; \
	done
	for f in ${INSTHDRS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/include/mpeg3; \
	done
	for f in ${AINSTHDRS}; do \
		${INSTALL_DATA} ${WRKSRC}/audio/$$f \
			${DESTDIR}${PREFIX}/include/mpeg3/audio; \
	done
	for f in ${VINSTHDRS}; do \
		${INSTALL_DATA} ${WRKSRC}/video/$$f \
			${DESTDIR}${PREFIX}/include/mpeg3/video; \
	done
	${INSTALL_LIB} ${WRKSRC}/work/libmpeg3.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/docs/index.html \
		${DESTDIR}${PREFIX}/share/doc/libmpeg3

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
