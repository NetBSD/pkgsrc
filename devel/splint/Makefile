# $NetBSD: Makefile,v 1.2 2003/03/29 12:40:40 jmmv Exp $
#

VERSION=	3.0.1.6
DISTNAME=	splint-${VERSION}.src
PKGNAME=	splint-${VERSION}
WRKSRC=		${WRKDIR}/splint-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://www.splint.org/downloads/
EXTRACT_SUFX= .tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://lclint.cs.virginia.edu/
COMMENT=	Statically check C programs

USE_GMAKE=	YES
GNU_CONFIGURE=  YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/splint.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
