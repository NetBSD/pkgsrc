# $NetBSD: Makefile,v 1.1.1.1 2000/12/10 05:11:31 jtb Exp $

DISTNAME=		minpack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org

WRKSRC=			${WRKDIR}/minpack
USE_FORTRAN=		YES

pre-build:
	@${SED} -e 's:%%F77%%:'${FC}':g' \
	< ${FILESDIR}/Makefile > ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/minpack
	${INSTALL_DATA} ${WRKSRC}/ex/file* ${WRKSRC}/ex/index* \
	${PREFIX}/share/examples/minpack

.include "../../mk/bsd.pkg.mk"