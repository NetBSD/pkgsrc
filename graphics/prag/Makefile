# $NetBSD: Makefile,v 1.8 2005/06/16 06:57:58 jlam Exp $

DISTNAME=	prag-1.0pl2
PKGNAME=	prag-1.0.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.kohala.com/start/troff/
EXTRACT_SUFX=	.shar

MAINTAINER=	itojun@kame.net
COMMENT=	Replacement to "grap" graph generator backend to pic

WRKSRC=		${WRKDIR}/prag-1.0
NO_BUILD=	yes

INSTALLATION_DIRS=	bin man/man1

post-patch:
	(cd ${WRKSRC}; ${MV} prag prag.orig)
	(cd ${WRKSRC}; ${SED} -e "1s,/bin/nawk,${AWK}," < prag.orig >prag)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/prag ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/prag.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
