# $NetBSD: Makefile,v 1.1.1.1 2000/12/10 03:57:16 jtb Exp $

DISTNAME=		dfftpack-20001209
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org

WRKSRC=			${WRKDIR}/dfftpack

USE_FORTRAN=		YES
USE_LIBTOOL=		YES

.include "../../mk/bsd.prefs.mk"

pre-build:
	@${RM} -f ${WRKDIR}/dfftpack/Makefile
	@${SED} -e 's:%%F77%%:'${FC}':g' \
	< ${FILESDIR}/Makefile > ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dfftpack
	@for f in README doc doc.double ; do \
	${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/dfftpack ; done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dfftpack
	${INSTALL_DATA} ${WRKSRC}/test.f ${PREFIX}/share/examples/dfftpack

.include "../../mk/bsd.pkg.mk"
