# $NetBSD: Makefile,v 1.4 2001/01/21 03:11:54 jtb Exp $

DISTNAME=		stalin
PKGNAME=		stalin-0.8
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.nj.nec.com/pub/qobi/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.neci.nj.nec.com/homepages/qobi/software.html

DEPENDS+=		boehm-gc-[0-9]*:../../devel/boehm-gc
DEPENDS+=		Mesa-[0-9]*:../../graphics/Mesa

EVAL_PREFIX+=		GC_PREFIX=boehm-gc MESA_PREFIX=Mesa
WRKSRC=			${WRKDIR}/${PKGNAME}

.if (${MACHINE_ARCH} == "alpha")
ALL_TARGET=		all-alpha
.else
ALL_TARGET=		all-32
.endif

post-patch:
	@${RM} -f ${WRKSRC}/benchmarks/*.orig
	@for i in stalin.sc stalin-32.c stalin-alpha.c \
	stalinc stalin.1 benchmarks/benchmark \
	benchmarks/compile-and-run-stalin-benchmark \
	benchmarks/compile-stalin-benchmark \
	benchmarks/make-define-application-example \
	benchmarks/make-hello benchmarks/make-xhello; do \
	${SED} -e 's:@PREFIX@:'${PREFIX}':g' \
	-e 's:@GC_PREFIX@:'${GC_PREFIX}':g' \
	-e 's:@MESA_PREFIX@:'${MESA_PREFIX}':g' \
	-e 's:@X11BASE@:'${X11BASE}':g' < ${WRKSRC}/$$i > \
	${WRKSRC}/$$i.tmp && ${MV} ${WRKSRC}/$$i.tmp ${WRKSRC}/$$i ; done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stalin ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/stalinc ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/stalin
	${INSTALL_DATA} ${WRKSRC}/libstalin.a ${PREFIX}/lib/stalin
	${INSTALL_DATA} ${WRKSRC}/gl-c.o ${PREFIX}/lib/stalin
	${INSTALL_DATA} ${WRKSRC}/xlib-c.o ${PREFIX}/lib/stalin
	@for s in ${WRKSRC}/include/*.sc; do \
	c="${INSTALL_DATA} $$s ${PREFIX}/lib/stalin/"; \
	${ECHO} $$c; $$c; \
	done
	${INSTALL_MAN} ${WRKSRC}/stalin.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/stalin
	@for f in ANNOUNCEMENT COPYING README stalin.el ; do \
	c="${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/stalin/"; \
	${ECHO} $$c; $$c; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/stalin/benchmarks
	@for b in ${WRKSRC}/benchmarks/*; do \
	c="${INSTALL_DATA} $$b ${PREFIX}/share/stalin/benchmarks/"; \
	${ECHO} $$c; $$c; \
	done

.include "../../mk/bsd.pkg.mk"
