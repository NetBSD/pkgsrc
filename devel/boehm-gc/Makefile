# $NetBSD: Makefile,v 1.19 2001/05/04 01:28:14 jlam Exp $
# FreeBSD Id: Makefile,v 1.1 1996/11/16 01:51:25 jdp Exp
#

DISTNAME=		gc5.3
PKGNAME=		boehm-gc-5.3
CATEGORIES=		devel
MASTER_SITES=		http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.hpl.hp.com/personal/Hans_Boehm/gc/
COMMENT=		Garbage collection and memory leak detection for C and C++

USE_GMAKE=		# defined

WRKSRC=			${WRKDIR}/gc
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
	${MV} ${WRKSRC}/gc.man ${WRKSRC}/gc.man.in

pre-build:
	${SED}	-e "s|@PREFIX@|${PREFIX}|g"				\
		${WRKSRC}/gc.man.in > ${WRKSRC}/gc.man

.include "../../mk/bsd.pkg.mk"
