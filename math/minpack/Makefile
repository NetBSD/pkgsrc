# $NetBSD: Makefile,v 1.8 2004/01/20 12:20:05 agc Exp $

DISTNAME=		minpack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		FORTRAN 77 library for the solution of nonlinear equations

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_FORTRAN=		YES
WRKSRC=			${WRKDIR}/minpack

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
