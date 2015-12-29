# $NetBSD: Makefile,v 1.1 2015/12/29 02:04:08 agc Exp $

DISTNAME=	pcg-c-0.94
PKGNAME=	${DISTNAME:S/-c//}
CATEGORIES=	math
MASTER_SITES=	http://www.pcg-random.org/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.pcg-random.org/
COMMENT=	Random number generator
LICENSE=	apache-2.0

USE_TOOLS+=	gmake
AUTO_MKDIRS=	yes

do-test:
	for t in check-pcg128i check-pcg128si check-pcg16i check-pcg16si \
		check-pcg32 check-pcg32f check-pcg32i check-pcg32s \
		check-pcg32si check-pcg32u check-pcg64 check-pcg64f \
		check-pcg64i check-pcg64s check-pcg64si check-pcg64u \
		check-pcg8i check-pcg8si check-pcg32-global		\
		check-pcg64-global; do					\
		(cd ${WRKSRC}/test-high && ./$$t);			\
	done
	for t in pcg32-demo pcg32-global-demo pcg32x2-demo pcg64-demo; do \
		(cd ${WRKSRC}/sample && ./$$t);				\
	done

.include "../../mk/bsd.pkg.mk"
