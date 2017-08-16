# $NetBSD: Makefile,v 1.6 2017/08/16 20:21:15 wiz Exp $

DISTNAME=	itexToMML
PKGNAME=	itex2MML-1.2.3
CATEGORIES=	textproc
MASTER_SITES=	http://golem.ph.utexas.edu/~distler/blog/files/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://golem.ph.utexas.edu/~distler/blog/itex2MML.html
COMMENT=	Converts itex equations to MathML

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison flex
WRKSRC=		${WRKDIR}/${DISTNAME}/itex-src

DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/itex2MML ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
