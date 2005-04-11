# $NetBSD: Makefile,v 1.22 2005/04/11 21:46:14 tv Exp $
#

DISTNAME=       awk
PKGNAME=        nawk-20040207
CATEGORIES=	lang
MASTER_SITES=   http://cm.bell-labs.com/who/bwk/

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://cm.bell-labs.com/who/bwk/
COMMENT=	Brian Kernighan's pattern-directed scanning and processing language

DIST_SUBDIR=	${PKGNAME}
WRKSRC=		${WRKDIR}

USE_GNU_TOOLS+=	yacc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKEFILE=	makefile
MAKE_FLAGS+=	CC=${CC:Q} YACC=${YACC:Q} CFLAGS=${CFLAGS:Q}
BUILD_TARGET=	a.out

INSTALLATION_DIRS=	bin man/man1

post-build:
	${SED} -e 's|awk|nawk|g' -e 's/Awk/Nawk/g' \
		${WRKSRC}/awk.1 > ${WRKSRC}/nawk.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/nawk
	${INSTALL_MAN} ${WRKSRC}/nawk.1 ${PREFIX}/man/man1/nawk.1

.include "../../mk/bsd.pkg.mk"
