# $NetBSD: Makefile,v 1.2 2000/04/20 08:26:11 agc Exp $
#

DISTNAME=       awk
PKGNAME=        nawk-19990620
CATEGORIES=	lang
MASTER_SITES=   http://cm.bell-labs.com/who/bwk/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cm.bell-labs.com/who/bwk/

DIST_SUBDIR=	${PKGNAME}

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	a.out

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/nawk
	${SED} -e 's|awk|nawk|g' ${WRKSRC}/awk.1 > ${PREFIX}/man/man1/nawk.1

.include "../../mk/bsd.pkg.mk"
