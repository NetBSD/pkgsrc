# $NetBSD: Makefile,v 1.14 2005/06/16 06:57:43 jlam Exp $

DISTNAME=	macfork-1.0
CATEGORIES=	converters
MASTER_SITES=	http://www.cs.cmu.edu/~ajw/public/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.cmu.edu/afs/cs/user/ajw/www/software/
COMMENT=	Tool for extracting data from Macintosh resource forks

WRKSRC=		${WRKDIR}/macfork
USE_LANGUAGE=	c c++
USE_TOOLS+=	gmake

DOCDIR=		${PREFIX}/share/doc/macfork

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/macfork ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
