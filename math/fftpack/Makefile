# $NetBSD: Makefile,v 1.15 2007/03/24 19:21:27 joerg Exp $

DISTNAME=		fftpack-20001130
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Single precision Fortran FFT subroutines

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_LANGUAGES=		fortran
WRKSRC=			${WRKDIR}/fftpack
INSTALLATION_DIRS=	lib share/doc/fftpack

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc ${PREFIX}/share/doc/fftpack

.include "../../mk/bsd.pkg.mk"
