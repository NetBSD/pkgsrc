# $NetBSD: Makefile,v 1.4 2002/11/11 20:07:33 jschauma Exp $
#

DISTNAME=	detex-2.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.purdue.edu/homes/trinkle/detex/
EXTRACT_SUFX=	.tar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.purdue.edu/homes/trinkle/detex/
COMMENT=	remove LaTeX commands

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/detex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/detex.1l ${PREFIX}/man/man1/detex.1

.include "../../mk/bsd.pkg.mk"
