# $NetBSD: Makefile,v 1.38 2004/04/03 10:26:14 hubertf Exp $
#

DISTNAME=		gc6.2
PKGNAME=		${DISTNAME:S/gc/boehm-gc-/}
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://www.hpl.hp.com/personal/Hans_Boehm/gc/
COMMENT=		Garbage collection and memory leak detection for C and C++


NOT_FOR_PLATFORM=	*-*-amd64 *-*-x86_64

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
INSTALLATION_DIRS=	man/man3

MAKE_ENV+=		COPTS="${CFLAGS}"

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
	@cd ${WRKSRC}; \
	${MAKE_PROGRAM} -f ${WRKSRC}/Makefile.direct bsd-libleak.a
	${INSTALL_DATA} ${WRKSRC}/bsd-libleak.a ${PREFIX}/lib/libleak.a
	${INSTALL_MAN} ${WRKSRC}/doc/gc.man ${PREFIX}/man/man3/gc.3

do-test:
	@cd ${WRKSRC}; \
	${RM} -f gctest && ${MAKE_PROGRAM} gctest && ./gctest && \
	${RM} -f test_cpp && ${MAKE_PROGRAM} test_cpp && ./test_cpp 10

.include "../../mk/bsd.pkg.mk"
