# $NetBSD: Makefile,v 1.1.1.1 1998/10/15 13:19:21 agc Exp $
#

DISTNAME=       awk
PKGNAME=        nawk-19980211
CATEGORIES=	lang
MASTER_SITES=   http://cm.bell-labs.com/who/bwk/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cm.bell-labs.com/who/bwk/

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	a.out

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/nawk
	${SED} -e 's|awk|nawk|g' ${WRKSRC}/awk.1 > ${PREFIX}/man/man1/nawk.1

.include "../../mk/bsd.pkg.mk"
