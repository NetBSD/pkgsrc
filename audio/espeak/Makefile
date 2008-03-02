# $NetBSD: Makefile,v 1.5 2008/03/02 06:10:31 jlam Exp $
#

DISTNAME=	espeak-1.31-source
PKGNAME=	espeak-1.31
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=espeak/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://espeak.sourceforge.net/
COMMENT=	Speech synthesizer

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/espeak-1.31-source/src

#LICENSE=	GPLv3

INSTALLATION_DIRS=	bin include lib share

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/espeak ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libespeak.so.1.1.31 ${DESTDIR}${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libespeak.so.1.1.31 \
		${DESTDIR}${PREFIX}/lib/libespeak.so.1
	${LN} -sf ${PREFIX}/lib/libespeak.so.1.1.31 \
		${DESTDIR}${PREFIX}/lib/libespeak.so
	${INSTALL_DATA} ${WRKSRC}/libespeak.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/speak_lib.h ${DESTDIR}${PREFIX}/include
	${CP} -r ${WRKDIR}/espeak-1.31-source/espeak-data \
		${DESTDIR}${PREFIX}/share

.include "../../audio/portaudio/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
