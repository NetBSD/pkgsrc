# $NetBSD: Makefile,v 1.9 2001/05/03 22:16:50 jtb Exp $

DISTNAME=		stalin
PKGNAME=		stalin-0.8
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.nj.nec.com/pub/qobi/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.neci.nj.nec.com/homepages/qobi/software.html
COMMENT=		Aggressively optimizing Scheme compiler

DEPENDS+=		boehm-gc-*:../../devel/boehm-gc

USE_MESA=		yes
WRKSRC=			${WRKDIR}/${PKGNAME}

GC_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		GC_PREFIX=boehm-gc

post-patch:
	@${RM} -f ${WRKSRC}/benchmarks/*.orig
	@for i in stalin.sc stalin-32.c stalin-alpha.c stalinc stalin.1	 \
	benchmarks/benchmark benchmarks/compile-and-run-stalin-benchmark \
	benchmarks/compile-stalin-benchmark				 \
	benchmarks/make-define-application-example			 \
	benchmarks/make-hello benchmarks/make-xhello; do		 \
	${SED} -e 's:@PREFIX@:'${PREFIX}':g'				 \
		-e 's:@GC_PREFIX@:'${GC_PREFIX}':g'			 \
		-e 's:@X11BASE@:'${X11BASE}':g' ${WRKSRC}/$$i >		 \
	${WRKSRC}/$$i.tmp && ${MV} ${WRKSRC}/$$i.tmp ${WRKSRC}/$$i;	 \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stalin ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/stalinc ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/stalin
	${INSTALL_DATA} ${WRKSRC}/libstalin.a ${PREFIX}/lib/stalin
	${INSTALL_DATA} ${WRKSRC}/gl-c.o ${PREFIX}/lib/stalin
	${INSTALL_DATA} ${WRKSRC}/xlib-c.o ${PREFIX}/lib/stalin
	${INSTALL_DATA} ${WRKSRC}/include/*.sc ${PREFIX}/lib/stalin/
	${INSTALL_MAN} ${WRKSRC}/stalin.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/stalin
	cd ${WRKSRC} && ${INSTALL_DATA} ANNOUNCEMENT COPYING README 	\
		stalin.el ${PREFIX}/share/stalin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/stalin/benchmarks
	${INSTALL_DATA} ${WRKSRC}/benchmarks/*  			\
		${PREFIX}/share/stalin/benchmarks/ 			\

.include "../../mk/bsd.pkg.mk"
