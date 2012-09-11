# $NetBSD: Makefile,v 1.20 2012/09/11 23:04:25 asau Exp $

DISTNAME=		odepack-20001130
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Systematized Collection of ODE Solvers

DEPENDS+=		linpack>=20010427:../../math/linpack

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_LANGUAGES=		fortran77
WRKSRC=			${WRKDIR}/odepack
INSTALLATION_DIRS=	lib

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/odepack
	cd ${WRKSRC} && ${INSTALL_DATA} doc readme ${DESTDIR}${PREFIX}/share/doc/odepack

.include "../../mk/bsd.pkg.mk"
