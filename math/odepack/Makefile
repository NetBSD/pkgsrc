# $NetBSD: Makefile,v 1.13 2004/01/20 12:20:05 agc Exp $

DISTNAME=		odepack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Systematized Collection of ODE Solvers

DEPENDS+=		linpack>=20010427:../../math/linpack

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_FORTRAN=		yes
WRKSRC=			${WRKDIR}/odepack

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/odepack
	cd ${WRKSRC} && ${INSTALL_DATA} doc readme ${PREFIX}/share/doc/odepack

.include "../../mk/bsd.pkg.mk"
