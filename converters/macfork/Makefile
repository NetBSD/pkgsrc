# $NetBSD: Makefile,v 1.17 2006/03/10 23:22:48 rillig Exp $

DISTNAME=	macfork-1.0
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.cs.cmu.edu/~ajw/public/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.cmu.edu/afs/cs/user/ajw/www/software/
COMMENT=	Tool for extracting data from Macintosh resource forks

WRKSRC=		${WRKDIR}/macfork
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

DOCDIR=		${PREFIX}/share/doc/macfork

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/macfork ${PREFIX:Q}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC:Q}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
