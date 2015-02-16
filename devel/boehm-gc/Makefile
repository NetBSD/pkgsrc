# $NetBSD: Makefile,v 1.80 2015/02/16 07:54:06 tnn Exp $

DISTNAME=	gc-7.4.2
PKGNAME=	${DISTNAME:S/gc/boehm-gc/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.hboehm.info/gc/gc_source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hboehm.info/gc/
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

.if ${OPSYS} == "Darwin" && empty(OS_VERSION:M[1-9].*)
CFLAGS+=		-D_XOPEN_SOURCE
.endif

.include "options.mk"

post-extract:
	mv ${WRKSRC}/src/* ${WRKSRC}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/gc.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/gc.3

do-test:
	cd ${WRKSRC} && \
	${RM} -f gctest && ${MAKE_PROGRAM} gctest && ./gctest && \
	${RM} -f test_cpp && ${MAKE_PROGRAM} test_cpp && ./test_cpp 10

.include "../../devel/libatomic_ops/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
