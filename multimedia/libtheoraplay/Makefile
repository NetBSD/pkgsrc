# $NetBSD: Makefile,v 1.2 2022/04/23 22:09:34 tnn Exp $

DISTNAME=	libtheoraplay-0.0.20210704
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=icculus/}
GITHUB_PROJECT=	theoraplay
GITHUB_TAG=	abd0bf6b42213bebecb5105ebcbe9b364db071c2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://icculus.org/theoraplay/
COMMENT=	Simple library to make decoding of Ogg Theora videos easier
LICENSE=	zlib

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
