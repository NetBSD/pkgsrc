# $NetBSD: Makefile,v 1.2 2002/04/01 00:07:56 cjep Exp $

DISTNAME=	macfork-1.0
WRKSRC=		${WRKDIR}/macfork
CATEGORIES=	converters
MASTER_SITES=	http://www.cs.cmu.edu/~ajw/public/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.cmu.edu/afs/cs/user/ajw/www/software/
COMMENT=	Tool for extracting data from Macintosh resource forks

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES

DOCDIR=		${PREFIX}/share/doc/macfork

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/macfork ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
