# $NetBSD: Makefile,v 1.14 2009/12/03 13:06:54 asau Exp $

DISTNAME=		dfftpack-20001209
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Double precision version of FFTPACK

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_LANGUAGES=		fortran
WRKSRC=			${WRKDIR}/dfftpack

INSTALLATION_DIRS=	lib share/doc/dfftpack share/examples/dfftpack

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	@for f in README doc doc.double ; do \
	${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/dfftpack ; done
	${INSTALL_DATA} ${WRKSRC}/test.f ${PREFIX}/share/examples/dfftpack

.include "../../mk/bsd.pkg.mk"
