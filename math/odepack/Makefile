# $NetBSD: Makefile,v 1.8 2001/05/03 22:16:51 jtb Exp $

DISTNAME=		odepack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
COMMENT=		Systematized Collection of ODE Solvers

DEPENDS+=		linpack>=20010427:../../math/linpack

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
WRKSRC=			${WRKDIR}/odepack
USE_FORTRAN=		YES


pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/odepack
	cd ${WRKSRC} && ${INSTALL_DATA} doc readme ${PREFIX}/share/doc/odepack

.include "../../mk/bsd.pkg.mk"
