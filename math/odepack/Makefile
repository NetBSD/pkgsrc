# $NetBSD: Makefile,v 1.1.1.1 2000/11/30 00:51:16 jtb Exp $

DISTNAME=		odepack-20001129
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org

WRKSRC=			${WRKDIR}/odepack
USE_LIBTOOL=		YES
USE_FORTRAN=		YES

FOPTS?=			=-O3

.include "../../mk/bsd.prefs.mk"

pre-build:
	@${SED} -e 's:%%FORTRAN%%:'${FC}':g;s:%%FOPTS%%:'${FOPTS}':g' \
	< ${FILESDIR}/Makefile > ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/odepack
	${INSTALL_DATA} ${WRKSRC}/doc ${PREFIX}/share/doc/odepack
	${INSTALL_DATA} ${WRKSRC}/readme ${PREFIX}/share/doc/odepack
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/odepack
	${INSTALL_DATA} ${WRKSRC}/demo.f ${PREFIX}/share/examples/odepack

.include "../../mk/bsd.pkg.mk"
