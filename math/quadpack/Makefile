# $NetBSD: Makefile,v 1.8 2003/06/02 01:18:23 jschauma Exp $

DISTNAME=		quadpack-20001130
WRKSRC=			${WRKDIR}/quadpack
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@netbsd.org
COMMENT=		Fortran subroutines for the solution of definite univariate integrals

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_FORTRAN=		YES

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/quadpack
	cd ${WRKSRC} && ${INSTALL_DATA} doc readme ${PREFIX}/share/doc/quadpack

.include "../../mk/bsd.pkg.mk"
