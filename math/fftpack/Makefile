# $NetBSD: Makefile,v 1.3 2000/12/01 01:49:46 jtb Exp $

DISTNAME=		fftpack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org

WRKSRC=			${WRKDIR}/fftpack

USE_LIBTOOL=		YES
UES_FORTRAN=		YES

.include "../../mk/bsd.prefs.mk"

post-extract:
	@${SED} -e 's:%%FORTRAN%%:'${FC}':g' \
	< ${FILESDIR}/Makefile > ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fftpack
	${INSTALL_DATA} ${WRKSRC}/doc ${PREFIX}/share/doc/fftpack

.include "../../mk/bsd.pkg.mk"