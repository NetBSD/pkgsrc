# $NetBSD: Makefile,v 1.1.1.1 2001/08/13 20:34:08 nra Exp $
#

DISTNAME=		bicom101
PKGNAME=		bicom-1.01
CATEGORIES=		archivers
MASTER_SITES=		http://www3.sympatico.ca/mtimmerm/bicom/
EXTRACT_SUFX=		.zip

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www3.sympatico.ca/mtimmerm/bicom/
COMMENT=		data compressor in the PPM family

LICENSE=		no-commercial-use
USE_BUILDLINK_ONLY=	yes
NO_WRKSUBDIR=		yes

do-build:
	for i in bialib bicom; do \
		cd ${WRKSRC}/$$i && \
		for j in *.cpp; do ${CXX} -c -I./ -I../bialib $$j; done; \
	done
	cd ${WRKSRC}/bicom && ${CXX} -o bicom *.o ../bialib/*.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bicom/bicom ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
