# $NetBSD: Makefile,v 1.1.1.1 2007/06/14 18:53:10 minskim Exp $

DISTNAME=	itexToMML
PKGNAME=	itex2MML-1.2.2
CATEGORIES=	textproc
MASTER_SITES=	http://golem.ph.utexas.edu/~distler/blog/files/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://golem.ph.utexas.edu/~distler/blog/itex2MML.html
COMMENT=	Converts itex equations to MathML

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison flex
WRKSRC=		${WRKDIR}/${DISTNAME}/itex-src

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/itex2MML ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
