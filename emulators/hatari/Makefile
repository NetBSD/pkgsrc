# $NetBSD: Makefile,v 1.1.1.1 2002/12/31 19:16:53 cjep Exp $
#

DISTNAME=	hatari-0.25
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hatari/}

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	http://hatari.sourceforge.net/
COMMENT=	Atari ST emulator

WRKSRC=		${WRKDIR}/hatari-0.25/src
USE_BUILDLINK2=	YES
USE_X11=	YES

ALL_TARGET=	hatari
USE_GMAKE=	yes
MAKE_FLAGS+=	DATADIR=${PREFIX}/share/hatari

HATARI_SHARE=	${PREFIX}/share/hatari

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hatari ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${HATARI_SHARE}
	${INSTALL_DATA} ${WRKSRC}/font8.bmp ${HATARI_SHARE}
	${INSTALL_DATA} ${WRKDIR}/hatari-0.25/readme.txt ${HATARI_SHARE}
	${INSTALL_DATA} ${WRKDIR}/hatari-0.25/authors.txt ${HATARI_SHARE}
	${INSTALL_DATA} ${WRKDIR}/hatari-0.25/gpl.txt ${HATARI_SHARE}

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
