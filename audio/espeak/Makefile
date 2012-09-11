# $NetBSD: Makefile,v 1.9 2012/09/11 23:59:31 asau Exp $
#

DISTNAME=	espeak-1.31-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=espeak/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://espeak.sourceforge.net/
COMMENT=	Speech synthesizer
#LICENSE=	GPLv3

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/${DISTNAME}/src

INSTALLATION_DIRS=	bin include lib share

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/espeak ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libespeak.so.1.1.31 ${DESTDIR}${PREFIX}/lib
	${LN} -sf libespeak.so.1.1.31 \
		${DESTDIR}${PREFIX}/lib/libespeak.so.1
	${LN} -sf libespeak.so.1.1.31 \
		${DESTDIR}${PREFIX}/lib/libespeak.so
	${INSTALL_LIB} ${WRKSRC}/libespeak.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/speak_lib.h ${DESTDIR}${PREFIX}/include
	${CP} -r ${WRKDIR}/espeak-1.31-source/espeak-data \
		${DESTDIR}${PREFIX}/share

.include "../../audio/portaudio/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
