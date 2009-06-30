# $NetBSD: Makefile,v 1.4 2009/06/30 00:07:10 joerg Exp $
#

DISTNAME=	nbench-byte-2.2.2
PKGNAME=	${DISTNAME:S/-byte//}
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.tux.org/~mayer/linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tux.org/~mayer/linux/
COMMENT=	Benchmark tool for CPU, FPU and memory

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

BUILD_TARGET=	default

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbench ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
