# $NetBSD: Makefile,v 1.6 2003/07/26 21:41:14 jmmv Exp $
#

DISTNAME=	hatari-0.30
PKGREVISION=	1
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

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
