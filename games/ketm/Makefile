# $NetBSD: Makefile,v 1.3 2001/12/05 05:28:59 jlam Exp $
#

DISTNAME=	ketm-0.0.4
CATEGORIES=	games
MASTER_SITES=	http://home.t-online.de/home/haslbeck/ketm/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://home.t-online.de/home/haslbeck/ketm/
COMMENT=	old-school 2d-scrolling shooter

ALL_TARGET=	ketm

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES

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
		${INSTALL_DATA} *.bmp ${PREFIX}/share/ketm/data

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
