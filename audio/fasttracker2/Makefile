# $NetBSD: Makefile,v 1.33 2019/08/02 17:16:33 fox Exp $

DISTNAME=	ft2clone-${DISTVERSION}-code
PKGNAME=	fasttracker2-${DISTVERSION:C/b/2./}
DISTVERSION=	b163
CATEGORIES=	audio
MASTER_SITES=	https://16-bits.org/ \
		${MASTER_SITE_FREEBSD_LOCAL:=ehaupt/}
EXTRACT_SUFX=	.zip

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://16-bits.org/
COMMENT=	Portable Fasttracker II clone in C using SDL 2
LICENSE=	modified-bsd AND cc-by-nc-sa-v4.0-license

WRKSRC=		${WRKDIR}/ft2-clone-code
USE_LANGUAGES=	c c++

LDFLAGS+=	-lSDL2 -lpthread -lstdc++ -lm
LDFLAGS.SunOS+=	-liconv

INSTALLATION_DIRS+=	bin share/pixmaps

SUBST_CLASSES+=		d2u
SUBST_MESSAGE.d2u=	Converting CRLF to LF.
SUBST_STAGE.d2u=	post-extract
SUBST_FILES.d2u=	src/*.[ch]
SUBST_FILTER_CMD.d2u=	${TR} -d '\r'

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} \
		${WRKSRC}/src/rtmidi/*.cpp ${WRKSRC}/src/gfxdata/*.c ${WRKSRC}/src/*.c \
		-o ${WRKSRC}/release/other/ft2-clone

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/other/ft2-clone \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/gfxdata/icon/ft2-clone.ico \
		${DESTDIR}${PREFIX}/share/pixmaps

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
