# $NetBSD: Makefile,v 1.7 2003/07/21 17:27:29 martti Exp $
#

DISTNAME=	detex-2.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.purdue.edu/homes/trinkle/detex/
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.purdue.edu/homes/trinkle/detex/
COMMENT=	Remove LaTeX commands

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/detex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/detex.1l ${PREFIX}/man/man1/detex.1

.include "../../mk/bsd.pkg.mk"
