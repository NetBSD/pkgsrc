# $NetBSD: Makefile,v 1.3 2000/12/01 01:50:44 jtb Exp $

DISTNAME=		odepack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org

WRKSRC=			${WRKDIR}/odepack
USE_LIBTOOL=		YES
USE_FORTRAN=		YES

.include "../../mk/bsd.prefs.mk"

pre-build:
	@${SED} -e 's:%%FORTRAN%%:'${FC}':g' \
	< ${FILESDIR}/Makefile > ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/odepack
	${INSTALL_DATA} ${WRKSRC}/doc ${PREFIX}/share/doc/odepack
	${INSTALL_DATA} ${WRKSRC}/readme ${PREFIX}/share/doc/odepack
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/odepack
	${INSTALL_DATA} ${WRKSRC}/demo.f ${PREFIX}/share/examples/odepack

.include "../../mk/bsd.pkg.mk"
