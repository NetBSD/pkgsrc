# $NetBSD: Makefile,v 1.5 2003/03/29 12:41:20 jmmv Exp $

DISTNAME=	prag-1.0pl2
PKGNAME=	prag-1.0.2
WRKSRC=		${WRKDIR}/prag-1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.kohala.com/start/troff/
EXTRACT_SUFX=	.shar

MAINTAINER=	itojun@kame.net
COMMENT=	replacement to "grap" graph generator backend to pic

NO_BUILD=	yes

post-patch:
	(cd ${WRKSRC}; ${MV} prag prag.orig)
	(cd ${WRKSRC}; ${SED} -e "1s,/bin/nawk,${AWK}," < prag.orig >prag)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/prag ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/prag.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
