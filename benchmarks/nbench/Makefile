# $NetBSD: Makefile,v 1.1.1.1 2005/09/03 06:26:21 xtraeme Exp $
#

DISTNAME=	nbench-byte-2.2.2
PKGNAME=	${DISTNAME:S/-byte//}
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.tux.org/~mayer/linux/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tux.org/~mayer/linux/
COMMENT=	Benchmark tool for CPU, FPU and memory

BUILD_TARGET=	default

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbench ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
