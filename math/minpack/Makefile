# $NetBSD: Makefile,v 1.4 2001/04/14 21:43:53 jtb Exp $

DISTNAME=		minpack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
COMMENT=		FORTRAN 77 library for the solution of nonlinear equations

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
WRKSRC=			${WRKDIR}/minpack
USE_FORTRAN=		YES

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"