# $NetBSD: Makefile,v 1.12 2003/03/16 14:51:01 cjep Exp $
#

DISTNAME=       awk
PKGNAME=        nawk-20030314
CATEGORIES=	lang
MASTER_SITES=   http://cm.bell-labs.com/who/bwk/

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	http://cm.bell-labs.com/who/bwk/
COMMENT=	Brian Kernighan's pattern-directed scanning and processing language

DIST_SUBDIR=	${PKGNAME}

WRKSRC=		${WRKDIR}
MAKEFILE=	makefile
MAKEFLAGS+=	CC=${CC:Q} YACC=${YACC:Q} CFLAGS=${CFLAGS:Q}
ALL_TARGET=	a.out

post-build:
	${SED} -e 's|awk|nawk|g' -e 's/Awk/Nawk/g' \
		${WRKSRC}/awk.1 > ${WRKSRC}/nawk.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/nawk
	${INSTALL_MAN} ${WRKSRC}/nawk.1 ${PREFIX}/man/man1/nawk.1

.include "../../mk/bsd.pkg.mk"
