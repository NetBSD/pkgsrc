# $NetBSD: Makefile,v 1.14 2009/12/11 18:10:56 asau Exp $

DISTNAME=		minpack-20001130
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		FORTRAN 77 library for the solution of nonlinear equations

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		fortran
WRKSRC=			${WRKDIR}/minpack

INSTALLATION_DIRS=	lib

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
