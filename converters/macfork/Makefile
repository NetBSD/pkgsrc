# $NetBSD: Makefile,v 1.6 2003/07/17 21:27:19 grant Exp $

DISTNAME=	macfork-1.0
WRKSRC=		${WRKDIR}/macfork
CATEGORIES=	converters
MASTER_SITES=	http://www.cs.cmu.edu/~ajw/public/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.cmu.edu/afs/cs/user/ajw/www/software/
COMMENT=	Tool for extracting data from Macintosh resource forks

USE_BUILDLINK2=	# defined
USE_GCC_SHLIB=	# defined
USE_GMAKE=	# defined

DOCDIR=		${PREFIX}/share/doc/macfork

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/macfork ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
