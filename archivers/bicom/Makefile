# $NetBSD: Makefile,v 1.18 2004/04/22 23:22:26 minskim Exp $
#

DISTNAME=		bicom101
PKGNAME=		bicom-1.01
CATEGORIES=		archivers
MASTER_SITES=		http://www3.sympatico.ca/mt0000/bicom/
EXTRACT_SUFX=		.zip

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www3.sympatico.ca/mt0000/bicom/bicom.html
COMMENT=		Data compressor in the PPM family

LICENSE=		no-commercial-use

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		yes
USE_GCC_SHLIB=		yes
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
