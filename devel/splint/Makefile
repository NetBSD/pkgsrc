# $NetBSD: Makefile,v 1.8 2005/05/22 20:07:55 jlam Exp $
#

VERSION=	3.1.1
DISTNAME=	splint-${VERSION}.src
PKGNAME=	splint-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://www.splint.org/downloads/
EXTRACT_SUFX= .tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://lclint.cs.virginia.edu/
COMMENT=	Statically check C programs

WRKSRC=		${WRKDIR}/splint-${VERSION}
USE_TOOLS+=	gmake
GNU_CONFIGURE=  YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/splint.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
