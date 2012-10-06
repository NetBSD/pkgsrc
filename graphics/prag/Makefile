# $NetBSD: Makefile,v 1.12 2012/10/06 14:11:15 asau Exp $

DISTNAME=	prag-1.0pl2
PKGNAME=	prag-1.0.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.kohala.com/start/troff/
EXTRACT_SUFX=	.shar

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Replacement to "grap" graph generator backend to pic

WRKSRC=		${WRKDIR}/prag-1.0
NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-patch:
	(cd ${WRKSRC}; ${MV} prag prag.orig)
	(cd ${WRKSRC}; ${SED} -e "1s,/bin/nawk,${AWK}," < prag.orig >prag)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/prag ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/prag.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
