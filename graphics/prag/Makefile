# $NetBSD: Makefile,v 1.2 2000/02/09 17:47:01 itojun Exp $

DISTNAME=	prag-1.0pl2
PKGNAME=	prag-1.0.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.kohala.com/start/troff/
EXTRACT_SUFX=	.shar

MAINTAINER=	itojun@kame.net

WRKSRC=		${WRKDIR}/prag-1.0
NO_BUILD=	yes

do-extract:
	${MKDIR} ${WRKDIR}
	(cd ${WRKDIR}; ${SH} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})

post-patch:
	(cd ${WRKSRC}; ${MV} prag prag.orig)
	(cd ${WRKSRC}; ${SED} -e "1s,/bin/nawk,${AWK}," < prag.orig >prag)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/prag ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/prag.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
