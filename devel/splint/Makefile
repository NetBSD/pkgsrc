# $NetBSD: Makefile,v 1.5 2004/01/20 12:13:29 agc Exp $
#

VERSION=	3.0.1.6
DISTNAME=	splint-${VERSION}.src
PKGNAME=	splint-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://www.splint.org/downloads/
EXTRACT_SUFX= .tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://lclint.cs.virginia.edu/
COMMENT=	Statically check C programs

WRKSRC=		${WRKDIR}/splint-${VERSION}
USE_GMAKE=	YES
GNU_CONFIGURE=  YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/splint.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
