# $NetBSD: Makefile,v 1.5 2005/03/24 21:12:50 wiz Exp $

DISTNAME=	9e
PKGNAME=	9e-1.0
CATEGORIES=	plan9 archivers
MASTER_SITES=	http://www.eecs.harvard.edu/~wkj/Software/9e/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.eecs.harvard.edu/~wkj/Software/9e/
COMMENT=	Explode Plan9 archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9e ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
