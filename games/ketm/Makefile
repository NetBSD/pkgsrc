# $NetBSD: Makefile,v 1.10 2004/01/24 13:30:56 grant Exp $
#

DISTNAME=	ketm-0.0.6
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://home.t-online.de/home/haslbeck/ketm/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://home.t-online.de/home/haslbeck/ketm/
COMMENT=	Old-school 2d-scrolling shooter

ALL_TARGET=	ketm

USE_BUILDLINK2=	YES
USE_X11=	YES
USE_GNU_TOOLS+=	make

post-patch:
	cd ${WRKSRC} &&							\
	for f in *.c; do						\
		${SED} "s,data/,${LOCALBASE}/share/ketm/data/,g" $${f}	\
			> $${f}.done;					\
		${MV} $${f}.done $${f};					\
	done

	${SED} "s,data/,${LOCALBASE}/share/ketm/data/,g"		\
		${WRKSRC}/font.h > ${WRKSRC}/font.h.done
	${MV} ${WRKSRC}/font.h.done ${WRKSRC}/font.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ketm ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/ketm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/ketm
	${INSTALL_DATA_DIR} ${PREFIX}/share/ketm/data
	cd ${WRKSRC}/data && 						\
		${INSTALL_DATA} *.bmp *.dat ${PREFIX}/share/ketm/data

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
