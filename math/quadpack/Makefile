# $NetBSD: Makefile,v 1.14 2007/03/24 19:21:28 joerg Exp $

DISTNAME=		quadpack-20001130
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Fortran subroutines for the solution of definite univariate integrals

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_LANGUAGES=		fortran
WRKSRC=			${WRKDIR}/quadpack

INSTALLATION_DIRS=	lib share/doc/quadpack

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} doc readme ${PREFIX}/share/doc/quadpack

.include "../../mk/bsd.pkg.mk"
