# $NetBSD: Makefile,v 1.27 2016/01/23 05:06:29 zafer Exp $
#

DISTNAME=		pbzip2-1.1.13
CATEGORIES=		archivers
MASTER_SITES=		http://compression.ca/pbzip2/
MASTER_SITES=		https://launchpad.net/pbzip2/1.1/1.1.13/+download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://compression.ca/pbzip2/
COMMENT=		Parallel implementation of the bzip2 block-sorting file compressor
#LICENSE=		pbzip2-license

PTHREAD_AUTO_VARS=	yes
PTHREAD_OPTS+=		require

USE_LANGUAGES=		c++

CPPFLAGS+=		-D_LARGEFILE_SOURCE=1
CPPFLAGS+=		-D_FILE_OFFSET_BITS=64
CPPFLAGS+=		-D_POSIX_PTHREAD_SEMANTICS
CPPFLAGS+=		-DUSE_STACKSIZE_CUSTOMIZATION
LIBS+=			-lbz2

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/pbzip2

do-build:
	cd ${WRKSRC} && \
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} -o pbzip2 pbzip2.cpp \
		BZ2StreamScanner.cpp ErrorContext.cpp ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pbzip2 \
		${DESTDIR}${PREFIX}/bin
	${LN} -s ${DESTDIR}${PREFIX}/bin/pbzip2 \
		${DESTDIR}${PREFIX}/bin/pbunzip2
	${LN} -s ${DESTDIR}${PREFIX}/bin/pbzip2 \
		${DESTDIR}${PREFIX}/bin/pbzcat
	${INSTALL_DATA} ${WRKSRC}/pbzip2.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/pbzip2
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/pbzip2

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
