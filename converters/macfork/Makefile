# $NetBSD: Makefile,v 1.3 2002/11/14 23:42:51 jlam Exp $

DISTNAME=	macfork-1.0
WRKSRC=		${WRKDIR}/macfork
CATEGORIES=	converters
MASTER_SITES=	http://www.cs.cmu.edu/~ajw/public/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.cmu.edu/afs/cs/user/ajw/www/software/
COMMENT=	Tool for extracting data from Macintosh resource forks

USE_BUILDLINK2=	# defined
USE_CXX=	# defined
USE_GMAKE=	# defined

DOCDIR=		${PREFIX}/share/doc/macfork

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/macfork ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
