# $NetBSD: Makefile,v 1.1.1.1 2000/10/18 09:55:53 itojun Exp $
#

DISTNAME=	detex-2.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.purdue.edu/homes/trinkle/detex/
EXTRACT_SUFX=	.tar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.purdue.edu/homes/trinkle/detex/

NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/detex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/detex.1l ${PREFIX}/man/man1/detex.1

.include "../../mk/bsd.pkg.mk"
