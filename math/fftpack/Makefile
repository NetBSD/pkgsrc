# $NetBSD: Makefile,v 1.9 2003/06/02 01:18:32 jschauma Exp $

DISTNAME=		fftpack-20001130
WRKSRC=			${WRKDIR}/fftpack
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@netbsd.org
COMMENT=		Single precision Fortran FFT subroutines

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_FORTRAN=		YES

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fftpack
	${INSTALL_DATA} ${WRKSRC}/doc ${PREFIX}/share/doc/fftpack

.include "../../mk/bsd.pkg.mk"
