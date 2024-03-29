# $NetBSD: Makefile,v 1.30 2023/12/16 00:02:57 zafer Exp $
#

DISTNAME=		pbzip2-1.1.13
CATEGORIES=		archivers
MASTER_SITES=		https://launchpad.net/pbzip2/1.1/1.1.13/+download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://compression.great-site.net/pbzip2/
COMMENT=		Parallel implementation of the bzip2 block-sorting file compressor
#LICENSE=		pbzip2-license

PTHREAD_AUTO_VARS=	yes
PTHREAD_OPTS+=		require

USE_LANGUAGES=		c c++

CPPFLAGS+=		-D_LARGEFILE_SOURCE=1
CPPFLAGS+=		-D_FILE_OFFSET_BITS=64
CPPFLAGS+=		-D_POSIX_PTHREAD_SEMANTICS
CPPFLAGS+=		-DUSE_STACKSIZE_CUSTOMIZATION
LIBS+=			-lbz2

# Fails with C++14 default language.
FORCE_CXX_STD=		c++03

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
