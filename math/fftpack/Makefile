# $NetBSD: Makefile,v 1.2 2000/11/30 00:40:20 jtb Exp $

DISTNAME=		fftpack-20001129
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org

WRKSRC=			${WRKDIR}/fftpack

USE_LIBTOOL=		YES
UES_FORTRAN=		YES

FOPTS?=			-O2

.include "../../mk/bsd.prefs.mk"

post-extract:
	@${SED} -e 's:%%FORTRAN%%:'${FC}':g;s:%%FOPTS%%:'${FOPTS}':g' \
	< ${FILESDIR}/Makefile > ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fftpack
	${INSTALL_DATA} ${WRKSRC}/doc ${PREFIX}/share/doc/fftpack

.include "../../mk/bsd.pkg.mk"