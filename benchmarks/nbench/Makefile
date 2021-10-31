# $NetBSD: Makefile,v 1.11 2021/10/31 19:58:56 jklos Exp $
#

DISTNAME=	nbench-byte-2.2.3
PKGNAME=	${DISTNAME:S/-byte//}
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.math.utah.edu/~mayer/linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.math.utah.edu/~mayer/linux/bmark.html
COMMENT=	Benchmark tool for CPU, FPU and memory

MAKE_JOBS_SAFE=		no
MKPIE_SUPPORTED=	no

BUILD_TARGET=	default

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS" && \
    (!empty(OS_VERSION:M5.1*) || ${ABI} == 64)
BUILDLINK_TRANSFORM+=	rm:-static
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbench ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
