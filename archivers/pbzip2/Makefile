# $NetBSD: Makefile,v 1.21 2009/01/03 18:33:55 wiz Exp $
#

DISTNAME=		pbzip2-1.0.4
CATEGORIES=		archivers
MASTER_SITES=		http://compression.ca/pbzip2/
#DIST_SUBDIR=		pbzip-1.0.2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://compression.ca/pbzip2/
COMMENT=		Parallel implementation of the bzip2 block-sorting file compressor

PKG_DESTDIR_SUPPORT=	user-destdir

PTHREAD_AUTO_VARS=	yes
PTHREAD_OPTS+=		require

USE_LANGUAGES=		c++

CPPFLAGS+=		-D_LARGEFILE_SOURCE=1
CPPFLAGS+=		-D_FILE_OFFSET_BITS=64
LIBS+=			-lbz2

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/pbzip2

do-build:
	cd ${WRKSRC} && \
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} -o pbzip2 pbzip2.cpp ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pbzip2 \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pbzip2.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/pbzip2
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/pbzip2

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
