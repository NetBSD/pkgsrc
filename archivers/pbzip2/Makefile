# $NetBSD: Makefile,v 1.2 2005/01/21 02:39:23 tv Exp $
#

DISTNAME=		pbzip2-0.8.3
CATEGORIES=		archivers
MASTER_SITES=		http://compression.ca/pbzip2/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://compression.ca/pbzip2/
COMMENT=		Parallel implementation of the bzip2 block-sorting file compressor

USE_BUILDLINK3=		yes
PTHREAD_AUTO_VARS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pbzip2 ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pbzip2
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${PREFIX}/share/doc/pbzip2
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/pbzip2

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
