# $NetBSD: Makefile,v 1.7 2009/05/19 08:59:01 wiz Exp $
#

DISTNAME=	espeak-1.31-source
PKGNAME=	espeak-1.31
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=espeak/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://espeak.sourceforge.net/
COMMENT=	Speech synthesizer
#LICENSE=	GPLv3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/espeak-1.31-source/src

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
