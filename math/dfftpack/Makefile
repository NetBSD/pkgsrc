# $NetBSD: Makefile,v 1.7 2003/06/02 01:18:33 jschauma Exp $

DISTNAME=		dfftpack-20001209
WRKSRC=			${WRKDIR}/dfftpack
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@netbsd.org
COMMENT=		Double precision version of FFTPACK

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
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
