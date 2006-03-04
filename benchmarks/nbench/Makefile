# $NetBSD: Makefile,v 1.2 2006/03/04 21:29:01 jlam Exp $
#

DISTNAME=	nbench-byte-2.2.2
PKGNAME=	${DISTNAME:S/-byte//}
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.tux.org/~mayer/linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tux.org/~mayer/linux/
COMMENT=	Benchmark tool for CPU, FPU and memory

BUILD_TARGET=	default

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbench ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
