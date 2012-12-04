# $NetBSD: Makefile,v 1.1 2012/12/04 10:32:53 msaitoh Exp $
#

DISTNAME=	ramspeed-2.6.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://alasir.com/software/ramspeed/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alasir.com/software/ramspeed/
COMMENT=	RAMspeed, a cache and memory benchmarking tool

MAKE_JOBS_SAFE=		no

BUILD_TARGET=	default

INSTALLATION_DIRS=	bin

do-build:
	(cd ${WRKSRC} ; ./build.sh)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ramspeed ${DESTDIR}${PREFIX}/bin

benchmark:
	-@${WRKSRC}/ramspeed -b 1 | tee ${WRKSRC}/ramspeed.out
	-@${WRKSRC}/ramspeed -b 2 | tee -a ${WRKSRC}/ramspeed.out
	-@${WRKSRC}/ramspeed -b 3 | tee -a ${WRKSRC}/ramspeed.out
	-@${WRKSRC}/ramspeed -b 4 | tee -a ${WRKSRC}/ramspeed.out
	-@${WRKSRC}/ramspeed -b 5 | tee -a ${WRKSRC}/ramspeed.out
	-@${WRKSRC}/ramspeed -b 6 | tee -a ${WRKSRC}/ramspeed.out
# And some other CPU dependent tests.

.include "../../mk/bsd.pkg.mk"
