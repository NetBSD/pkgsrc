# $NetBSD: Makefile,v 1.12 2003/07/17 21:47:52 grant Exp $

DISTNAME=		odepack-20001130
WRKSRC=			${WRKDIR}/odepack
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Systematized Collection of ODE Solvers

DEPENDS+=		linpack>=20010427:../../math/linpack

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_FORTRAN=		yes

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/odepack
	cd ${WRKSRC} && ${INSTALL_DATA} doc readme ${PREFIX}/share/doc/odepack

.include "../../mk/bsd.pkg.mk"
