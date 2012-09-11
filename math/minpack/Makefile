# $NetBSD: Makefile,v 1.16 2012/09/11 23:04:24 asau Exp $

DISTNAME=		minpack-20001130
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		FORTRAN 77 library for the solution of nonlinear equations

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_LANGUAGES=		fortran77
WRKSRC=			${WRKDIR}/minpack

INSTALLATION_DIRS=	lib

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
