# $NetBSD: Makefile,v 1.2 2001/02/17 17:37:19 wiz Exp $
#

DISTNAME=	detex-2.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.purdue.edu/homes/trinkle/detex/
EXTRACT_SUFX=	.tar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.purdue.edu/homes/trinkle/detex/
COMMENT=	remove LaTeX commands

NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/detex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/detex.1l ${PREFIX}/man/man1/detex.1

.include "../../mk/bsd.pkg.mk"
