# $NetBSD: Makefile,v 1.3 2003/07/17 21:21:03 grant Exp $
# FreeBSD Id: ports/archivers/9e/Makefile,v 1.5 2002/07/22 03:58:19 fenner Exp

DISTNAME=	9e
PKGNAME=	9e-1.0
CATEGORIES=	plan9 archivers
MASTER_SITES=	http://www.eecs.harvard.edu/~wkj/Software/9e/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.eecs.harvard.edu/~wkj/Software/9e/
COMMENT=	Explode Plan9 archives

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9e ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
