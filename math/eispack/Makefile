# $NetBSD: Makefile,v 1.9 2004/01/20 12:20:04 agc Exp $

DISTNAME=		eispack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Fortran routines for the solution of eigenvalue problems

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_FORTRAN=		YES
WRKSRC=			${WRKDIR}/eispack

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
