# $NetBSD: Makefile,v 1.9 2004/04/11 07:21:59 snj Exp $

DISTNAME=	macfork-1.0
CATEGORIES=	converters
MASTER_SITES=	http://www.cs.cmu.edu/~ajw/public/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.cmu.edu/afs/cs/user/ajw/www/software/
COMMENT=	Tool for extracting data from Macintosh resource forks

WRKSRC=		${WRKDIR}/macfork
USE_BUILDLINK3=	# defined
USE_GCC_SHLIB=	# defined
USE_GNU_TOOLS+=	make

DOCDIR=		${PREFIX}/share/doc/macfork

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/macfork ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
