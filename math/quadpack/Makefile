# $NetBSD: Makefile,v 1.1.1.1 2000/11/30 01:25:21 jtb Exp $

DISTNAME=		quadpack-20001129
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org

WRKSRC=			${WRKDIR}/quadpack

USE_LIBTOOL=		YES
UES_FORTRAN=		YES

FOPTS?=			-O3

.include "../../mk/bsd.prefs.mk"

pre-build:
	@${SED} -e 's:%%FORTRAN%%:'${FC}':g;s:%%FOPTS%%:'${FOPTS}':g' \
	< ${FILESDIR}/Makefile > ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/quadpack
	@for i in doc readme ; do \
	${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/quadpack ; done

.include "../../mk/bsd.pkg.mk"
