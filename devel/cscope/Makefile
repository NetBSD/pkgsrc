# $NetBSD: Makefile,v 1.2 2000/04/21 03:50:24 hubertf Exp $

DISTNAME=	cscope-13.0-2
PKGNAME=	cscope-13.0.2
CATEGORIES=	devel
MASTER_SITES=	http://download.sourceforge.net/cscope/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cscope.sourceforge.net/

WRKSRC=		${WRKDIR}/cscope-13.0

post-install:
		${INSTALL_MAN} ${WRKSRC}/doc/cscope.1 ${PREFIX}/man/cat1

.include <../../mk/bsd.pkg.mk>
