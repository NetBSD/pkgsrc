# $NetBSD: Makefile,v 1.73 2013/11/18 19:53:57 wiz Exp $

DISTNAME=	gc-7.2e
PKGNAME=	${DISTNAME:S/gc/boehm-gc/}
CATEGORIES=	devel
MASTER_SITES=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/
COMMENT=	Garbage collection and memory leak detection for C and C++

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME:C/[a-z]$//}

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-cplusplus
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/doc
INSTALLATION_DIRS=	${PKGMANDIR}/man3

MAKE_ENV+=		COPTS=${CFLAGS:M*:Q}

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if !empty(EXTRACT_USING:Mpax)
EXTRACT_ELEMENTS=	-u
.endif

.if ${MACHINE_ARCH} == "mipsel"
CFLAGS+=		-D__MIPSEL__
.endif

.if ${OPSYS} == "Darwin" && empty(OS_VERSION:M[1-9].*)
CFLAGS+=		-D_XOPEN_SOURCE
.endif

.include "options.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/gc.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/gc.3

do-test:
	cd ${WRKSRC} && \
	${RM} -f gctest && ${MAKE_PROGRAM} gctest && ./gctest && \
	${RM} -f test_cpp && ${MAKE_PROGRAM} test_cpp && ./test_cpp 10

.include "../../mk/bsd.pkg.mk"
