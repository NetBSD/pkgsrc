# $NetBSD: Makefile,v 1.8 2003/07/17 21:47:27 grant Exp $

DISTNAME=		eispack-20001130
WRKSRC=			${WRKDIR}/eispack
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Fortran routines for the solution of eigenvalue problems

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_FORTRAN=		YES

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
