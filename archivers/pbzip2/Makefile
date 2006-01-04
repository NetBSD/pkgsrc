# $NetBSD: Makefile,v 1.10 2006/01/04 22:37:38 wiz Exp $
#

DISTNAME=		pbzip2-0.9.5
CATEGORIES=		archivers
MASTER_SITES=		http://compression.ca/pbzip2/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://compression.ca/pbzip2/
COMMENT=		Parallel implementation of the bzip2 block-sorting file compressor

PTHREAD_AUTO_VARS=	yes
PTHREAD_OPTS+=		require

CPPFLAGS+=		-D_LARGEFILE_SOURCE=1
CPPFLAGS+=		-D_FILE_OFFSET_BITS=64
LIBS+=			-lbz2

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC}; \
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} -o pbzip2 pbzip2.cpp ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pbzip2 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pbzip2.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pbzip2
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/pbzip2
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pbzip2

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
