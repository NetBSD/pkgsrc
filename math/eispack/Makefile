# $NetBSD: Makefile,v 1.5 2001/04/14 21:43:51 jtb Exp $

DISTNAME=		eispack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
COMMENT=		Fortran routines for the solution of eigenvalue problems

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
WRKSRC=			${WRKDIR}/eispack
USE_FORTRAN=		YES

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
