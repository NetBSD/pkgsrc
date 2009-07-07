# $NetBSD: Makefile,v 1.4 2009/07/07 21:43:58 joerg Exp $

DISTNAME=	itexToMML
PKGNAME=	itex2MML-1.2.3
CATEGORIES=	textproc
MASTER_SITES=	http://golem.ph.utexas.edu/~distler/blog/files/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://golem.ph.utexas.edu/~distler/blog/itex2MML.html
COMMENT=	Converts itex equations to MathML

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison flex
WRKSRC=		${WRKDIR}/${DISTNAME}/itex-src

DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/itex2MML ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
