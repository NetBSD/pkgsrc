# $NetBSD: Makefile,v 1.5 2005/05/10 00:01:07 rillig Exp $
#

DISTNAME=		pbzip2-0.9.2
CATEGORIES=		archivers
MASTER_SITES=		http://compression.ca/pbzip2/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://compression.ca/pbzip2/
COMMENT=		Parallel implementation of the bzip2 block-sorting file compressor

PTHREAD_AUTO_VARS=	yes
PTHREAD_OPTS+=		require
MAKE_FLAGS+=		LDADD=${LIBS:Q}" -lbz2"
MAKEFILE=		${FILESDIR}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pbzip2 ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pbzip2
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${PREFIX}/share/doc/pbzip2
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/pbzip2

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
