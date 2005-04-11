# $NetBSD: Makefile,v 1.6 2005/04/11 21:44:48 tv Exp $

DISTNAME=	9e
PKGNAME=	9e-1.0
CATEGORIES=	plan9 archivers
MASTER_SITES=	http://www.eecs.harvard.edu/~wkj/Software/9e/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.eecs.harvard.edu/~wkj/Software/9e/
COMMENT=	Explode Plan9 archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9e ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
