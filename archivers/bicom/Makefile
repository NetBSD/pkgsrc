# $NetBSD: Makefile,v 1.22 2006/05/10 12:31:46 gdt Exp $
#

DISTNAME=		bicom101
PKGNAME=		bicom-1.01
PKGREVISION=		1
CATEGORIES=		archivers
MASTER_SITES=		http://www3.sympatico.ca/mt0000/bicom/
EXTRACT_SUFX=		.zip

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www3.sympatico.ca/mt0000/bicom/bicom.html
COMMENT=		Data compressor in the PPM family

LICENSE=		bicom-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin

do-build:
	for i in bialib bicom; do					\
		cd ${WRKSRC}/$$i &&					\
		for f in *.cpp; do					\
			${CXX} ${CXXFLAGS} -I./ -I../bialib		\
				-c $$f;				\
		done;							\
	done
	cd ${WRKSRC}/bicom &&						\
		${CXX} ${CXXFLAGS} ${LDFLAGS}				\
			-o bicom *.o ../bialib/*.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bicom/bicom ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
