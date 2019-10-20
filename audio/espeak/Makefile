# $NetBSD: Makefile,v 1.13 2019/10/20 11:10:47 nia Exp $

MINOR_VER=	48
DISTNAME=	espeak-1.${MINOR_VER}.04-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=espeak/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://espeak.sourceforge.net/
COMMENT=	Speech synthesizer
LICENSE=	gnu-gpl-v3

BUILD_DIRS=	src
USE_LANGUAGES=	c c++03
USE_TOOLS+=	gmake pax

MAKE_FLAGS+=	DATADIR=${PREFIX}/share/espeak-data

# use portaudio v19
MAKE_FLAGS+=	WAVE=wave.cpp
MAKE_FLAGS+=	LIB_AUDIO=-lportaudio
MAKE_FLAGS+=	USE_AUDIO=-DUSE_PORTAUDIO

PLIST_SUBST+=	MINOR_VER=${MINOR_VER}

CXXFLAGS+=	-funsigned-char

INSTALLATION_DIRS=	bin include lib share

pre-configure:
	${CP} ${WRKSRC}/src/portaudio19.h ${WRKSRC}/src/portaudio.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/espeak ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/src/libespeak.so.1.1.${MINOR_VER} ${DESTDIR}${PREFIX}/lib
	${LN} -sf libespeak.so.1.1.${MINOR_VER} \
		${DESTDIR}${PREFIX}/lib/libespeak.so.1
	${LN} -sf libespeak.so.1.1.${MINOR_VER} \
		${DESTDIR}${PREFIX}/lib/libespeak.so
	${INSTALL_LIB} ${WRKSRC}/src/libespeak.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/speak_lib.h ${DESTDIR}${PREFIX}/include
	cd ${WRKSRC}/espeak-data && \
		${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/espeak-data

.include "../../audio/portaudio/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
