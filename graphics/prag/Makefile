# $NetBSD: Makefile,v 1.1.1.1 2000/02/09 17:36:19 itojun Exp $

DISTNAME=	prag-1.0pl2
PKGNAME=	prag-1.0.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.kohala.com/start/troff/
EXTRACT_SUFX=	.shar

MAINTAINER=	itojun@kame.net

WRKSRC=		${WRKDIR}/prag-1.0

do-extract:
	${MKDIR} ${WRKDIR}
	(cd ${WRKDIR}; ${SH} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})

do-patch:
	(cd ${WRKSRC}; ${MV} prag prag.orig)
	(cd ${WRKSRC}; ${SED} -e "1s,/bin/nawk,${AWK}," < prag.orig >prag)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/prag ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/prag.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
