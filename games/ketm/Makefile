# $NetBSD: Makefile,v 1.13 2004/10/03 00:14:45 tv Exp $
#

DISTNAME=	ketm-0.0.6
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://home.t-online.de/home/haslbeck/ketm/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://home.t-online.de/home/haslbeck/ketm/
COMMENT=	Old-school 2d-scrolling shooter

ALL_TARGET=	ketm

USE_BUILDLINK3=	YES
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

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
