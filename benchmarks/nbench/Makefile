# $NetBSD: Makefile,v 1.5 2012/02/16 10:56:10 hans Exp $
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

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS" && \
    (!empty(OS_VERSION:M5.1*) || ${ABI} == 64)
BUILDLINK_TRANSFORM+=	rm:-static
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbench ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
