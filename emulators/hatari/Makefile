# $NetBSD: Makefile,v 1.3 2003/05/02 11:54:49 wiz Exp $
#

DISTNAME=	hatari-0.25
PKGREVISION=	1
WRKSRC=		${WRKDIR}/hatari-0.25/src
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hatari/}

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	http://hatari.sourceforge.net/
COMMENT=	Atari ST emulator

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
