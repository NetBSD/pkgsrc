# $NetBSD: Makefile,v 1.1.1.1 2002/11/18 13:36:20 cjep Exp $
# FreeBSD Id: ports/archivers/9e/Makefile,v 1.5 2002/07/22 03:58:19 fenner Exp

DISTNAME=	9e
PKGNAME=	9e-1.0
CATEGORIES=	plan9 archivers
MASTER_SITES=	http://www.eecs.harvard.edu/~wkj/Software/9e/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.eecs.harvard.edu/~wkj/Software/9e/
COMMENT=	Explode Plan9 archives

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9e ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
