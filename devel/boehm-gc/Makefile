# $NetBSD: Makefile,v 1.21 2001/11/19 20:11:00 jlam Exp $
# FreeBSD Id: Makefile,v 1.1 1996/11/16 01:51:25 jdp Exp
#

DISTNAME=		gc6.0
PKGNAME=		boehm-gc-6.0
CATEGORIES=		devel
MASTER_SITES=		http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.hpl.hp.com/personal/Hans_Boehm/gc/
COMMENT=		Garbage collection and memory leak detection for C and C++

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES

MAKE_ENV+=		COPTS="${CFLAGS}"

ALL_TARGET=		BSD-pkg-all
INSTALL_TARGET=		BSD-pkg-install

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

do-install:
	${INSTALL_DATA} ${WRKSRC}/bsd-libgc.a ${PREFIX}/lib/libgc.a
	${INSTALL_DATA} ${WRKSRC}/bsd-libleak.a ${PREFIX}/lib/libleak.a
	${INSTALL_DATA} ${WRKSRC}/include/gc.h ${WRKSRC}/include/gc_cpp.h \
	    ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/doc/gc.man ${PREFIX}/man/man3/gc.3

.include "../../mk/bsd.pkg.mk"
