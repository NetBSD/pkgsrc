# $NetBSD: Makefile,v 1.10 2004/01/20 12:20:05 agc Exp $

DISTNAME=		quadpack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Fortran subroutines for the solution of definite univariate integrals

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_FORTRAN=		YES
WRKSRC=			${WRKDIR}/quadpack

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/quadpack
	cd ${WRKSRC} && ${INSTALL_DATA} doc readme ${PREFIX}/share/doc/quadpack

.include "../../mk/bsd.pkg.mk"
