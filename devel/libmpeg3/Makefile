# $NetBSD: Makefile,v 1.4 2001/11/17 06:28:20 itohy Exp $
#

DISTNAME=	libmpeg3-1.3
CATEGORIES=	devel audio graphics
MASTER_SITES=	http://heroines.sourceforge.net/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://heroines.sourceforge.net/libmpeg3.php3
COMMENT=	MPEG decoding library

.if (${MACHINE_ARCH} == "i386")
BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.else
CONFIGURE_ARGS+= --no-mmx --no-css
.endif

USE_BUILDLINK_ONLY=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

post-configure:
	${ECHO} "CFLAGS+=-O2" >>${WRKSRC}/global_config
	${ECHO} "CFLAGS+=-I${BUILDLINK_DIR}/include" >>${WRKSRC}/global_config
	${ECHO} "CFLAGS+=-D_FILE_OFFSET_BITS=64" >>${WRKSRC}/global_config

INSTHDRS=	bitstream.h libmpeg3.h mpeg3atrack.h mpeg3css.h \
	mpeg3demux.h mpeg3io.h mpeg3private.h \
	mpeg3private.inc mpeg3title.h mpeg3vtrack.h timecode.h
AINSTHDRS=	ac3.h mpeg3audio.h
VINSTHDRS=	idct.h mpeg3video.h slice.h

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/mpeg3
	for f in ${INSTHDRS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/include/mpeg3; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/include/mpeg3/audio
	for f in ${AINSTHDRS}; do \
		${INSTALL_DATA} ${WRKSRC}/audio/$$f \
			${PREFIX}/include/mpeg3/audio; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/include/mpeg3/video
	for f in ${VINSTHDRS}; do \
		${INSTALL_DATA} ${WRKSRC}/video/$$f \
			${PREFIX}/include/mpeg3/video; \
	done
	${INSTALL_DATA} ${WRKSRC}/work/libmpeg3.a ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/libmpeg3
	${INSTALL_DATA} ${WRKSRC}/docs/index.html \
		${PREFIX}/share/doc/html/libmpeg3

.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
