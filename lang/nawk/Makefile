# $NetBSD: Makefile,v 1.5 2001/09/09 20:36:32 agc Exp $
#

DISTNAME=       awk
PKGNAME=        nawk-20001115
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
