# $NetBSD: Makefile,v 1.4 2017/08/16 20:45:37 wiz Exp $
#

DISTNAME=	chest-3.19
PKGNAME=	${DISTNAME}.20080412
CATEGORIES=	games
MASTER_SITES=	http://www.drb.insel.de/~heiner/Chess/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} answer.c analyse.c fac.c \
		mate2.c input.c

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.drb.insel.de/~heiner/Chess/chest.html
COMMENT=	Chess problem solver

MAKE_FILE=	Templates/Makefile.simple

DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin share/doc/chest share/examples/chest

post-extract:
	${MV} -f ${WRKDIR}/*.c ${WRKSRC}

do-install:
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} dchest ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_DATA} COPYRIGHT Doc/PGN_Standard.txt README_LONG \
		${DESTDIR}${PREFIX}/share/doc/chest && \
	${INSTALL_DATA} EPD/*epd ${DESTDIR}${PREFIX}/share/examples/chest

.include "../../mk/bsd.pkg.mk"
