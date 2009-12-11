# $NetBSD: Makefile,v 1.15 2009/12/11 17:36:50 asau Exp $

DISTNAME=		eispack-20001130
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Fortran routines for the solution of eigenvalue problems

PKG_DESTDIR_SUPPORT=	user-destdir

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_LANGUAGES=		fortran
WRKSRC=			${WRKDIR}/eispack

INSTALLATION_DIRS=	lib

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
