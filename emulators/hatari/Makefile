# $NetBSD: Makefile,v 1.7 2004/01/01 03:18:15 cjep Exp $
#

DISTNAME=	hatari-0.45
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hatari/}

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://hatari.sourceforge.net/
COMMENT=	Atari ST emulator

USE_BUILDLINK2=	YES
USE_X11=	YES
USE_GMAKE=	YES

ALL_TARGET=	hatari
MAKE_FLAGS+=	DATADIR="${PREFIX}/share/hatari"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hatari ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/hatari
	${INSTALL_DATA} ${WRKSRC}/font8.bmp ${PREFIX}/share/hatari
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hatari
	cd ${WRKSRC}/.. && ${INSTALL_DATA} *.txt ${PREFIX}/share/doc/hatari
	cd ${WRKSRC}/../doc && ${INSTALL_DATA} *.txt manual.html	\
			${PREFIX}/share/doc/hatari

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
