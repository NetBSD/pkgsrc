# $NetBSD: Makefile,v 1.4 2001/02/02 00:23:52 jtb Exp $

DISTNAME=		odepack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
WRKSRC=			${WRKDIR}/odepack
USE_FORTRAN=		YES

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/odepack
	${INSTALL_DATA} ${WRKSRC}/doc ${PREFIX}/share/doc/odepack
	${INSTALL_DATA} ${WRKSRC}/readme ${PREFIX}/share/doc/odepack

.include "../../mk/bsd.pkg.mk"
