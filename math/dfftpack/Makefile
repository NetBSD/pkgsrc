# $NetBSD: Makefile,v 1.4 2001/02/17 18:22:18 wiz Exp $

DISTNAME=		dfftpack-20001209
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org
COMMENT=		Double precision version of FFTPACK

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
WRKSRC=			${WRKDIR}/dfftpack
USE_FORTRAN=		YES

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dfftpack
	@for f in README doc doc.double ; do \
	${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/dfftpack ; done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dfftpack
	${INSTALL_DATA} ${WRKSRC}/test.f ${PREFIX}/share/examples/dfftpack

.include "../../mk/bsd.pkg.mk"
