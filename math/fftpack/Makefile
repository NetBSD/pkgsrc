# $NetBSD: Makefile,v 1.7 2001/04/14 21:43:52 jtb Exp $

DISTNAME=		fftpack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
COMMENT=		Single precision Fortran FFT subroutines

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
WRKSRC=			${WRKDIR}/fftpack
USE_FORTRAN=		YES

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fftpack
	${INSTALL_DATA} ${WRKSRC}/doc ${PREFIX}/share/doc/fftpack

.include "../../mk/bsd.pkg.mk"