# $NetBSD: Makefile,v 1.1 2021/01/24 18:22:25 maya Exp $

DISTNAME=	99e5fc74603e
PKGNAME=	libtheoraplay-0.0.20190909
CATEGORIES=	multimedia
MASTER_SITES=	https://hg.icculus.org/icculus/theoraplay/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hg.icculus.org/icculus/theoraplay/archive/
COMMENT=	Simple library to make decoding of Ogg Theora videos easier
LICENSE=	zlib

WRKSRC=	${WRKDIR}/theoraplay-99e5fc74603e


do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} ${LDFLAGS} -fPIC -shared -I${PREFIX}/include \
		-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib \
		-lpthread -logg -lvorbis -ltheoradec -o \
		${WRKSRC}/libtheoraplay.so \
		theoraplay.c


INSTALLATION_DIRS=	lib include
do-install:
	${INSTALL_DATA} ${WRKSRC}/*theora*.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libtheoraplay.so \
		${DESTDIR}${PREFIX}/lib

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
