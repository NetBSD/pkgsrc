# $NetBSD: Makefile,v 1.1.1.1 2000/12/10 11:07:31 jtb Exp $

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
	@for i in stalin.sc stalin-32.c stalin-alpha.c stalin.1 \
	stalinc benchmarks/make-define-application-example \
	benchmarks/benchmark benchmarks/compile-and-run-stalin-benchmark \
	benchmarks/compile-stalin-benchmark \
	benchmarks/make-define-application-example \
	benchmarks/make-hello benchmarks/make-xhello ; do \
	${SED} -e 's:%%PREFIX%%:'${PREFIX}':g' \
	-e 's:%%GC_PREFIX%%:'${GC_PREFIX}':g' \
	-e 's:%%MESA_PREFIX%%:'${MESA_PREFIX}':g' \
	-e 's:%%X11BASE%%:'${X11BASE}':g' < ${WRKSRC}/$$i > \
	${WRKSRC}/$$i.tmp && ${MV} -f ${WRKSRC}/$$i.tmp ${WRKSRC}/$$i ; done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stalin ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/stalinc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libstalin.a ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/lib/stalin
	${INSTALL_DATA} ${WRKSRC}/gl-c.o ${WRKSRC}/xlib-c.o \
	${PREFIX}/lib/stalin
	${INSTALL_DATA} ${WRKSRC}/include/*.sc ${PREFIX}/lib/stalin
	${INSTALL_MAN} ${WRKSRC}/stalin.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/stalin
	@for f in ANNOUNCEMENT COPYING README stalin.el ; do \
	${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/stalin ; done
	${INSTALL_DATA_DIR} ${PREFIX}/share/stalin/benchmarks
	${INSTALL_DATA} ${WRKSRC}/benchmarks/*.sc \
	${WRKSRC}/benchmarks/*.sed ${WRKSRC}/benchmarks/*.sed \
	${WRKSRC}/benchmarks/*.tst ${WRKSRC}/benchmarks/*.pgm \
	${WRKSRC}/benchmarks/*.cform ${WRKSRC}/benchmarks/*.c \
	${PREFIX}/share/stalin/benchmarks
	${INSTALL_SCRIPT} ${WRKSRC}/benchmarks/compile-* \
	${WRKSRC}/benchmarks/benchmark \
	${WRKSRC}/benchmarks/make-* ${WRKSRC}/benchmarks/run-* \
	${PREFIX}/share/stalin/benchmarks

.include "../../mk/bsd.pkg.mk"
