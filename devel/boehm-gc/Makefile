# $NetBSD: Makefile,v 1.42 2004/10/03 00:13:25 tv Exp $
#

DISTNAME=	gc6.3
PKGREVISION=	2
PKGNAME=	${DISTNAME:S/gc/boehm-gc-/}
CATEGORIES=	devel
MASTER_SITES=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/
COMMENT=	Garbage collection and memory leak detection for C and C++


PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-cplusplus --disable-threads
USE_LANGUAGES=		c c++
INSTALLATION_DIRS=	man/man3

MAKE_ENV+=		COPTS=${CFLAGS:Q}

#TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if defined(EXTRACT_USING_PAX)
EXTRACT_ELEMENTS=	-u
.endif

.if ${MACHINE_ARCH} == "mipsel"
CFLAGS+=		-D__MIPSEL__
.endif

post-extract:
	${MV} ${WRKSRC}/doc/gc.man ${WRKSRC}/doc/gc.man.in

pre-build:
	${SED}	-e "s|@PREFIX@|${PREFIX}|g"				\
		${WRKSRC}/doc/gc.man.in > ${WRKSRC}/doc/gc.man

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/gc.man ${PREFIX}/man/man3/gc.3

do-test:
	@cd ${WRKSRC}; \
	${RM} -f gctest && ${MAKE_PROGRAM} gctest && ./gctest && \
	${RM} -f test_cpp && ${MAKE_PROGRAM} test_cpp && ./test_cpp 10

.include "../../mk/bsd.pkg.mk"
