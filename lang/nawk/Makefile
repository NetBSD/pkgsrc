# $NetBSD: Makefile,v 1.6 2002/09/26 17:12:43 jschauma Exp $
#

DISTNAME=       awk
PKGNAME=        nawk-20020628
CATEGORIES=	lang
MASTER_SITES=   http://cm.bell-labs.com/who/bwk/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cm.bell-labs.com/who/bwk/
COMMENT=	Brian Kernighan's pattern-directed scanning and processing language

DIST_SUBDIR=	${PKGNAME}

WRKSRC=		${WRKDIR}
MAKEFILE=	makefile
ALL_TARGET=	a.out

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/nawk
	${SED} -e 's|awk|nawk|g' ${WRKSRC}/awk.1 > ${PREFIX}/man/man1/nawk.1

.include "../../mk/bsd.pkg.mk"
