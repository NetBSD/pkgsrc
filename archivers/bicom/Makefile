# $NetBSD: Makefile,v 1.7 2003/03/29 12:40:01 jmmv Exp $
#

DISTNAME=		bicom101
PKGNAME=		bicom-1.01
WRKSRC=			${WRKDIR}
CATEGORIES=		archivers
MASTER_SITES=		http://www3.sympatico.ca/mt0000/bicom/
EXTRACT_SUFX=		.zip

MAINTAINER=		collver1@attbi.com
HOMEPAGE=		http://www3.sympatico.ca/mt0000/bicom/bicom.html
COMMENT=		data compressor in the PPM family

LICENSE=		no-commercial-use
USE_BUILDLINK2=		# defined

do-build:
	for i in bialib bicom; do					\
		cd ${WRKSRC}/$$i &&					\
		for file in *.cpp; do					\
			${BUILDLINK_CXX} ${CXXFLAGS} -I./ -I../bialib	\
				-c $$file;				\
		done;							\
	done
	cd ${WRKSRC}/bicom &&						\
		${BUILDLINK_CXX} ${CXXFLAGS} -o bicom *.o ../bialib/*.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bicom/bicom ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
