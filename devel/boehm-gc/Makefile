# $NetBSD: Makefile,v 1.28 2003/05/22 16:46:48 jmmv Exp $
#

DISTNAME=		gc6.2alpha5
PKGNAME=		${DISTNAME:S/gc/boehm-gc-/}
CATEGORIES=		devel
MASTER_SITES=		http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://www.hpl.hp.com/personal/Hans_Boehm/gc/
COMMENT=		Garbage collection and memory leak detection for C and C++

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

MAKE_ENV+=		COPTS="${CFLAGS}"

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
	${MAKE} -f ${WRKSRC}/Makefile.direct bsd-libleak.a
	${INSTALL_DATA} ${WRKSRC}/bsd-libleak.a ${PREFIX}/lib/libleak.a
	${INSTALL_MAN} ${WRKSRC}/doc/gc.man ${PREFIX}/man/man3/gc.3

.include "../../mk/bsd.pkg.mk"
