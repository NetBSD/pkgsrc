# $NetBSD: Makefile,v 1.17 2010/07/30 10:36:31 asau Exp $

DISTNAME=		quadpack-20001130
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Fortran subroutines for the solution of definite univariate integrals

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_LANGUAGES=		fortran77
WRKSRC=			${WRKDIR}/quadpack

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	lib share/doc/quadpack

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} doc readme ${DESTDIR}${PREFIX}/share/doc/quadpack

.include "../../mk/bsd.pkg.mk"
