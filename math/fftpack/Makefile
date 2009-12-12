# $NetBSD: Makefile,v 1.17 2009/12/12 19:43:41 asau Exp $

DISTNAME=		fftpack-20001130
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Single precision Fortran FFT subroutines

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_LANGUAGES=		fortran
WRKSRC=			${WRKDIR}/fftpack
INSTALLATION_DIRS=	lib share/doc/fftpack
PKG_DESTDIR_SUPPORT=	user-destdir

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc ${DESTDIR}${PREFIX}/share/doc/fftpack

.include "../../mk/bsd.pkg.mk"
