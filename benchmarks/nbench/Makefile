# $NetBSD: Makefile,v 1.12 2024/04/20 13:48:24 nia Exp $
#

DISTNAME=	nbench-byte-2.2.3
PKGNAME=	${DISTNAME:S/-byte//}
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.math.utah.edu/~mayer/linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.math.utah.edu/~mayer/linux/bmark.html
COMMENT=	Benchmark tool for CPU, FPU and memory

MAKE_JOBS_SAFE=		no

BUILD_TARGET=	default
MAKE_FLAGS+=	LINKFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbench ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
