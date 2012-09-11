# $NetBSD: Makefile,v 1.6 2012/09/11 22:37:13 asau Exp $
#

DISTNAME=	nbench-byte-2.2.2
PKGNAME=	${DISTNAME:S/-byte//}
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.tux.org/~mayer/linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tux.org/~mayer/linux/
COMMENT=	Benchmark tool for CPU, FPU and memory

MAKE_JOBS_SAFE=		no

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
