# $NetBSD: Makefile,v 1.11 2004/10/03 00:14:40 tv Exp $
#

DISTNAME=	hatari-0.45
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hatari/}

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://hatari.sourceforge.net/
COMMENT=	Atari ST emulator

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=	YES
USE_X11=	YES
USE_GNU_TOOLS+=	make

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

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
