# $NetBSD: Makefile,v 1.1 2021/01/23 20:16:11 js Exp $

DISTNAME=	ft2-clone-1.43
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=8bitbubsy/}
GITHUB_PROJECT=	ft2-clone
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/8bitbubsy/ft2-clone/
COMMENT=	Fasttracker II clone for Windows/macOS/Linux
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin

do-build:
	cd ${WRKSRC}/src/rtmidi && ${CXX} -c -O2 -DNDEBUG \
		$$(sdl2-config --cflags) *.cpp
	cd ${WRKSRC}/src/gfxdata && ${CC} -c -O2 -DNDEBUG \
		$$(sdl2-config --cflags) *.c
	cd ${WRKSRC}/src/mixer && ${CC} -c -O2 -DNDEBUG \
		$$(sdl2-config --cflags) *.c
	cd ${WRKSRC}/src && ${CC} -c -O2 -DNDEBUG $$(sdl2-config --cflags) *.c
	cd ${WRKSRC} && ${CXX} -o ft2-clone \
		$$(sdl2-config --libs) -liconv \
		src/rtmidi/*.o \
		src/gfxdata/*.o \
		src/mixer/*.o \
		src/*.o

do-install:
	cd ${WRKSRC} && ${INSTALL} -m 755 ft2-clone \
		${DESTDIR}${PREFIX}/bin/ft2-clone

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
