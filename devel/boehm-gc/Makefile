# $NetBSD: Makefile,v 1.107 2023/12/29 01:09:23 zafer Exp $

DISTNAME=	gc-8.2.4
PKGNAME=	${DISTNAME:S/gc/boehm-gc/}
CATEGORIES=	devel
MASTER_SITES=	https://www.hboehm.info/gc/gc_source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.hboehm.info/gc/
COMMENT=	Garbage collection and memory leak detection for C and C++

USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-cplusplus
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/doc
PKGCONFIG_OVERRIDE=	bdw-gc.pc.in
INSTALLATION_DIRS=	${PKGMANDIR}/man3

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_PLATFORM:MDarwin-10.6.*}
CFLAGS+=		-D_XOPEN_SOURCE
.endif

.include "options.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/gc.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/gc.3
# as of 8.2.0, these are installed conditionally, but something is wrong - make sure they get installed
	${INSTALL_DATA} ${WRKSRC}/include/gc_gcj.h ${DESTDIR}${PREFIX}/include/gc
	${INSTALL_DATA} ${WRKSRC}/include/gc_pthread_redirects.h ${DESTDIR}${PREFIX}/include/gc

# historical pkgsrc test target, can be removed in one of the next updates
.PHONY: manual-do-test
manual-do-test:
	cd ${WRKSRC} && \
	${RM} -f gctest && ${MAKE_PROGRAM} gctest && ./gctest && \
	${RM} -f test_cpp && ${MAKE_PROGRAM} test_cpp && ./test_cpp 10

.include "../../devel/libatomic_ops/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
