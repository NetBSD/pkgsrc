# $NetBSD: Makefile,v 1.2 2000/12/01 01:51:33 jtb Exp $

DISTNAME=		quadpack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org

WRKSRC=			${WRKDIR}/quadpack

USE_LIBTOOL=		YES
UES_FORTRAN=		YES

.include "../../mk/bsd.prefs.mk"

pre-build:
	@${SED} -e 's:%%FORTRAN%%:'${FC}':g' \
	< ${FILESDIR}/Makefile > ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/quadpack
	@for i in doc readme ; do \
	${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/quadpack ; done

.include "../../mk/bsd.pkg.mk"
