# $NetBSD: Makefile,v 1.2 2002/06/15 20:57:51 wiz Exp $

DISTNAME=		cilk-5.3.1
CATEGORIES=		lang parallel
MASTER_SITES=		http://supertech.lcs.mit.edu/cilk/ \
			ftp://theory.lcs.mit.edu/pub/cilk/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://supertech.lcs.mit.edu/cilk/
COMMENT=		multithreaded parallel programming language based on ANSI C

GNU_CONFIGURE=		# defined
USE_BUILDLINK_ONLY= 	# defined
USE_GMAKE=		# defined
USE_PTHREAD=		native pth

LTCONFIG_OVERRIDE= 	${WRKSRC}/ltconfig

INFO_FILES=		cilk-faq.info

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cilk
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING			\
		FAQ/cilk-faq.ascii README THANKS doc/manual.ps		\
		${PREFIX}/share/doc/cilk
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cilk
	cd ${WRKSRC}/examples && ${INSTALL_DATA} *.cilk *.c *.input	\
		${PREFIX}/share/examples/cilk
	${INSTALL_DATA} ${WRKSRC}/FAQ/cilk-faq.info ${PREFIX}/info

.include "../../mk/pthread.buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
